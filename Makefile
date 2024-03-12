CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = LinkedList

all: $(TARGET)

$(TARGET): LinkedList.c
	$(CC) $(CFLAGS) LinkedList.c -o $(TARGET)

clean:
	rm -f $(TARGET)