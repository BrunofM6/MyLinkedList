LANG = gcc
CFLAGS = -Wall -Werror -Wextra
FILE = LinkedList

all: $(FILE)

$(FILE): LinkedList.c
	$(LANG) $(CFLAGS) LinkedList.c -o $(FILE)

clean:
	rm -f $(FILE)