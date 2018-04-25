ifndef CC
	CC=gcc
endif

ifndef CFLAGS
	CFLAGS=-Wall -Wextra -g -std=c11
endif

C_CHECK=cppcheck
RM=rm
RMFLAG=-rf
TARGET=test_type.out

all: run

check:
	$(C_CHECK) *.h *.c

run: compile
	./$(TARGET)

compile: trim
	$(CC) $(CFLAGS) -o $(TARGET) test_type.c

trim:
	perl -lpi -e "s{\s+$$}{}g;" *

clean:
	$(RM) $(RMFLAG) $(TARGET)
