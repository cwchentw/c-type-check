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
TARGET=test_type_check.out

ifndef PREFIX
	PREFIX=/usr/local
endif

.PHONY: all lint memo test comple clean install

all: test

memo:
	$(MEM_CHECK) ./$(TARGET)
	echo $$?

test: compile
	./$(TARGET)
	echo $$?

compile: trim
	$(CC) $(CFLAGS) -o $(TARGET) test_type_check.c

trim:
	perl -lpi -e "s{\s+$$}{}g;" *

lint:
	$(LINT) *.h *.c

clean:
	$(RM) $(TARGET)

install:
	install -m 644 type_check.h $(PREFIX)/include
