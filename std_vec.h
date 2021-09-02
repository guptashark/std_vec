#ifndef STD_VEC_H_
#define STD_VEC_H_

#include <stdbool.h>
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

void std_vec_print(std_vec *v, void (*type_printer)(void *));

void std_vec_push_back(std_vec *v, void *obj);

// Algorithms
bool std_vec_all_of(std_vec *v, bool (*unary_predicate)(void *));

void std_vec_for_each(std_vec *v, void (*unary_fn)(void *));

#endif
