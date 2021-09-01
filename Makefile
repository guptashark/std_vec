CC = clang
CFLAGS = -Wall -Werror -Wextra -std=c17

all: main.o
	$(CC) main.o

clean:
	rm *.o
	rm a.out
