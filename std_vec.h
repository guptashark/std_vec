#ifndef STD_VEC_H_
#define STD_VEC_H_

#include <stdbool.h>
#include <stddef.h>

// TODO Create a policy for increasing array size,
// and allow user to set it.

#ifdef __cplusplus
extern "C" {
#endif

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

// Element access
void std_vec_at(std_vec *v, size_t pos, void *dst);

void *std_vec_at_ptr(std_vec *v, size_t pos);

void std_vec_set_at(std_vec *v, size_t pos, void *obj);

void std_vec_front(std_vec *v, void *dst);

void *std_vec_front_ptr(std_vec *v);

void std_vec_back(std_vec *v, void *dst);

void *std_vec_back_ptr(std_vec *v);

// Capacity
bool std_vec_empty(std_vec *v);

size_t std_vec_size(std_vec *v);

size_t std_vec_capacity(std_vec *v);

void std_vec_print(std_vec *v, void (*type_printer)(void *));

// Modifiers
void std_vec_clear(std_vec *v);

void std_vec_push_back(std_vec *v, void *obj);

void std_vec_pop_back(std_vec *v);

// Algorithms
bool std_vec_all_of(std_vec *v, bool (*unary_predicate)(void *));

void std_vec_for_each(std_vec *v, void (*unary_fn)(void *));

#ifdef __cplusplus
} // extern "C"
#endif

#endif
