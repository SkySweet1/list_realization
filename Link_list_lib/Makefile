CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./include
TARGET = program

SRCS = src/linkedlist.c examples/main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run