CC = clang
CFLAGS = -Wall -Werror -Wextra -std=c17

all: main.o std_vec.o std_vec_iter.o
	$(CC) main.o std_vec.o std_vec_iter.o

clean:
	rm *.o
	rm a.out
