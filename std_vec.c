#include "std_vec.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void std_vec_ctor_default(std_vec *v, size_t type_size) {

	// TODO: error in case type_size is 0?
	v->type_size = type_size;
	v->capacity = 8;
	v->size = 0;

	v->data = malloc(type_size * v->capacity);
}

void std_vec_ctor_copy(std_vec *v, std_vec *other) {
	v->type_size = other->type_size;
	v->capacity = other->capacity;
	v->size = other->size;

	v->data = malloc(v->type_size * v->capacity);
	memcpy(v->data, other->data, v->type_size * v->size);
}

void std_vec_dtor(std_vec *v) {
	free(v->data);
}

// TODO What happens when the pos is larger than the size?
void std_vec_at(std_vec *v, size_t pos, void *dst) {
	memcpy(dst, v->data + v->type_size * pos, v->type_size);
}

// TODO What happens when the pos is larger than the size?
void *std_vec_at_ptr(std_vec *v, size_t pos) {
	return v->data + v->type_size * pos;
}

void std_vec_set_at(std_vec *v, size_t pos, void *obj) {
	memcpy(v->data + v->type_size * pos, obj, v->type_size);
}

void std_vec_front(std_vec *v, void *dst) {
	memcpy(dst, v->data, v->type_size);
}

void *std_vec_front_ptr(std_vec *v) {
	return v->data;
}

void std_vec_back(std_vec *v, void *dst) {
	memcpy(dst, v->data + v->type_size * (v->size - 1), v->type_size);
}

void *std_vec_back_ptr(std_vec *v) {
	return v->data + v->type_size * (v->size - 1);
}

bool std_vec_empty(std_vec *v) {
	return v->size == 0;
}

size_t std_vec_size(std_vec *v) {
	return v->size;
}

size_t std_vec_capacity(std_vec *v) {
	return v->capacity;
}

static void increase_capacity(std_vec *v) {
	v->capacity = v->capacity + 8;
	unsigned char *nd = malloc(v->type_size * v->capacity);

	// TODO Check if malloc has returned null.
	memcpy(nd, v->data, v->type_size * v->size);
	free(v->data);
	v->data = nd;
}

void std_vec_clear(std_vec *v) {
	memset(v->data, 0, v->type_size * v->size);
	v->size = 0;
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

// TODO: Document that popback on an empty vector is undefined.
// TODO: Document that this is "safe" in that it clears out the
//       memory of whatever was deleted so that anyone holding
//       a ptr to it will immediately know, vs having their data
//       stomped over later.
void std_vec_pop_back(std_vec *v) {
	v->size--;
	memset(v->data + v->type_size * v->size, 0, v->type_size);
}

void std_vec_print(std_vec *v, void (*type_printer)(void *)) {
	for (size_t i = 0; i < v->size; ++i) {
		type_printer(v->data + v->type_size * i);
		printf(" ");
	}

	printf("\n");
}

bool std_vec_all_of(std_vec *v, bool (*unary_predicate)(void *)) {
	size_t i = 0;
	bool all_true = true;
	while (i < v->size && all_true) {
		all_true = unary_predicate(v->data + v->type_size * i);
		i++;
	}

	return all_true;
}

void std_vec_for_each(std_vec *v, void (*unary_fn)(void *)) {
	for (size_t i = 0; i < v->size; ++i) {
		unary_fn(v->data + i * v->type_size);
	}
}
