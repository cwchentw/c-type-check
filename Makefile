ifndef CC
	CC=gcc
endif

ifndef CFLAGS
	CFLAGS=-Wall -Wextra -g -std=c11
endif

LINT=cppcheck
MEM_CHECK=valgrind --quiet
RM=rm
RMFLAG=-rf
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
	$(RM) $(RMFLAG) $(TARGET)

install:
	install -m 644 type_check.h $(PREFIX)/include
