CC=gcc
RM=rm
RMFLAG=-rf
TARGET=test_type

all: run

run: compile
	./$(TARGET)

compile:
	$(CC) -g -fsanitize=address -o $(TARGET) test_type.c -std=c11

clean:
	$(RM) $(RMFLAG) $(TARGET)
