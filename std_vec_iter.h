#ifndef STD_VEC_ITER_H_
#define STD_VEC_ITER_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct std_vec_iter {
	size_t pos;
} std_vec_iter;

bool std_vec_iter_eq(std_vec_iter *a, std_vec_iter *b);

#endif
