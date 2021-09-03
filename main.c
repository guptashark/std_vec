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

static void mult_two(void *n) {
	int *p = (int *)n;
	*p = (*p) * 2;
}

static void vec_test_01(void) {
	std_vec vec_obj;
	std_vec *v = &vec_obj;
	std_vec_ctor_default(v, sizeof(int));

	for (int i = 7; i < 15; ++i) {
		std_vec_push_back(v, &i);
	}

	{
		int back;
		std_vec_back(v, &back);
		assert(back == 14);

		int front;
		std_vec_front(v, &front);
		assert(front == 7);
	}

	{
		int *back_ptr = std_vec_back_ptr(v);
		assert(*back_ptr == 14);

		int *front_ptr = std_vec_front_ptr(v);
		assert(*front_ptr == 7);
	}

	std_vec_dtor(v);
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

	std_vec_for_each(&v, mult_two);

	std_vec_print(&v, print_int);

	std_vec_dtor(&v);

	vec_test_01();

	return 0;
}
