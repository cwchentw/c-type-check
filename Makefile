ifndef CC
	CC=gcc
endif

ifndef CFLAGS
	CFLAGS=-Wall -Wextra -g -std=c11
endif

C_CHECK=cppcheck
MEM_CHECK=valgrind
RM=rm
RMFLAG=-rf
TARGET=test_type_check.out

ifndef PREFIX
	PREFIX=/usr/local
endif

all: run

check:
	$(C_CHECK) *.h *.c

mem:
	$(MEM_CHECK) ./$(TARGET)
	echo $$?

run: compile
	./$(TARGET)
	echo $$?

compile: trim
	$(CC) $(CFLAGS) -o $(TARGET) test_type_check.c

trim:
	perl -lpi -e "s{\s+$$}{}g;" *

clean:
	$(RM) $(RMFLAG) $(TARGET)

install:
	install -m 644 type_check.h $(PREFIX)/include
