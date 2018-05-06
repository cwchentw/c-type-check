ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

CC=

ifndef CC
	ifeq ($(detected_OS),Windows)
		CC=cl
	else ifeq ($(detected_OS),Darwin)
		CC=clang
	else
		CC=gcc
	endif
endif

ifndef CFLAGS
	ifeq ($(CC),cl)
		CFLAGS=/Wall /sdl /Zi
	else ifeq($(detected_OS),Darwin)
		ifeq ($(CC),clang)
			CFLAGS=-O1 -Wall -g -std=c99 -fsanitize=address -fno-omit-frame-pointer
		else
			CFLAGS=-Wall -Wextra -g -std=c11
		endif
	else
		CFLAGS=-Wall -Wextra -g -std=c11
	endif
endif

ifeq ($(detected_OS),Windows)
	RM=del
endif

LINT=cppcheck
MEM_CHECK=valgrind --quiet

ifeq ($(detected_OS),Windows)
	TARGET=test_tyoe_check.exe
else
	TARGET=test_type_check.out
endif

ifndef PREFIX
	PREFIX=/usr/local
endif

.PHONY: all lint memo test comple clean install

all: test

memo:
ifeq ($(detected_OS),Windows)
	@echo "Not supported"
else ifeq ($(detected_OS),Darwin)
	ASAN_OPTIONS=symbolize=1 ASAN_SYMBOLIZER_PATH=$(shell which llvm-symbolizer) ./$(TARGET)
	echo $$?
else
	$(MEM_CHECK) ./$(TARGET)
	echo $$?
endif

test: compile
ifeq ($(detected_OS),Windows)
	.\$(TARGET)
	echo %errorlevel%
else
	./$(TARGET)
	echo $$?
endif

compile: trim
ifeq ($(CC),cl)
	$(CC) $(CFLAGS) /Fe:$(TARGET) test_type_check.c
else
	$(CC) $(CFLAGS) -o $(TARGET) test_type_check.c
endif

trim:
	perl -lpi -e "s{\s+$$}{}g;" *

lint:
	$(LINT) type_check.h test_type_check.c

clean:
	$(RM) $(TARGET)

install:
ifeq ($(detected_OS),Windows)
	@echo "Not supported"
else
	install -m 644 type_check.h $(PREFIX)/include
endif
