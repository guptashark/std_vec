#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "std_vec.h"

static void print_int(void *n) {
	printf("%d", *(int *)n);
}

static bool is_not_negative(void *n) {
	int x = *(int *)n;
	return x >= 0;
}

static bool is_positive(void *n) {
	int x = *(int *)n;
	return x > 0;
}

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	printf("std_vec version 0.01\n");

	std_vec v;
	std_vec_ctor_default(&v, sizeof(int));

	for (int i = 0; i < 20; ++i) {
		std_vec_push_back(&v, &i);
	}

	assert(std_vec_all_of(&v, is_not_negative));
	assert(!std_vec_all_of(&v, is_positive));

	std_vec v_02;
	std_vec_ctor_copy(&v_02, &v);

	std_vec_print(&v, print_int);

	std_vec_print(&v_02, print_int);

	std_vec_dtor(&v);

	return 0;
}
