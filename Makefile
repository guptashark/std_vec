CC = clang
CFLAGS = -Wall -Werror -Wextra -std=c17

all: main.o std_vec.o
	$(CC) main.o std_vec.o

clean:
	rm *.o
	rm a.out
