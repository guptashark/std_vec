#ifndef STD_VEC_H_
#define STD_VEC_H_

#include "std_vec_iter.h"

#include <stddef.h>

// TODO Create a policy for increasing array size,
// and allow user to set it.

typedef struct std_vec {
	size_t type_size;
	size_t capacity;
	size_t size;
	unsigned char *data;
} std_vec;

// TODO change type to allow returning error codes?
void std_vec_ctor_default(std_vec *v, size_t type_size);

void std_vec_ctor_copy(std_vec *v, std_vec *other);

void std_vec_dtor(std_vec *v);

// Iterators
std_vec_iter std_vec_begin(std_vec *v);

std_vec_iter std_vec_end(std_vec *v);

// Modifiers
void std_vec_print(std_vec *v, void (*type_printer)(void *));

void std_vec_push_back(std_vec *v, void *obj);

#endif
