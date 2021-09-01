#include <stdio.h>

#include "std_vec.h"

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	printf("std_vec version 0.01\n");

	std_vec v;
	std_vec_ctor_default(&v, sizeof(int));
	std_vec_dtor(&v);

	return 0;
}
