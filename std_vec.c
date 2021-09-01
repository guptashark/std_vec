#include "std_vec.h"

#include <stdlib.h>

void std_vec_ctor_default(std_vec *v, size_t type_size) {

	// TODO: error in case type_size is 0?
	v->type_size = type_size;
	v->capacity = 8;
	v->size = 0;

	v->data = malloc(type_size * v->capacity);
}

void std_vec_dtor(std_vec *v) {
	free(v->data);
}
