#include <stdio.h>

#include "std_vec.h"

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	printf("std_vec version 0.01\n");

	std_vec v;
	std_vec_ctor_default(&v, sizeof(int));

	for (int i = 0; i < 20; ++i) {
		std_vec_push_back(&v, &i);
	}

	std_vec_dtor(&v);

	return 0;
}
