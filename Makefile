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
TARGET=test_type.out

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
	$(CC) $(CFLAGS) -o $(TARGET) test_type.c

trim:
	perl -lpi -e "s{\s+$$}{}g;" *

clean:
	$(RM) $(RMFLAG) $(TARGET)
