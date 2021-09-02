#include "std_vec_iter.h"

bool std_vec_iter_eq(std_vec_iter *a, std_vec_iter *b) {
	return a->pos == b->pos;
}

bool std_vec_iter_neq(std_vec_iter *a, std_vec_iter *b) {
	return a->pos != b->pos;
}
