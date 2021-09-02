#include "std_vec.h"

#include <string.h>
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

static void increase_capacity(std_vec *v) {
	v->capacity = v->capacity + 8;
	unsigned char *nd = malloc(v->type_size * v->capacity);

	// TODO Check if malloc has returned null.
	memcpy(nd, v->data, v->type_size * v->size);
	free(v->data);
	v->data = nd;
}

void std_vec_push_back(std_vec *v, void *obj) {
	if (v->size == v->capacity) {
		increase_capacity(v);
	}

	unsigned char *offset = NULL;
	offset = v->data + v->size * v->type_size;
	memcpy(v->data + v->size * v->type_size, obj, v->type_size);
	v->size++;
}
