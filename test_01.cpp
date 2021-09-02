#include <cassert>
#include <iostream>

using namespace std;

#include "std_vec.h"

class rational_num {
	public:
	int numerator;
	int denominator;
};

static void rn_print(void *rn_ptr) {
	rational_num *rn = (rational_num *)rn_ptr;
	cout << "[" << rn->numerator << "/" << rn->denominator << "] ";
}

int main(void) {

	std_vec v_obj;
	std_vec *v = &v_obj;
	std_vec_ctor_default(v, sizeof(rational_num));

	for (int i = 0; i < 11; ++i) {
		rational_num rn = {i + 1, i + 2};
		std_vec_push_back(v, &rn);
	}

	std_vec_for_each(v, rn_print);
	cout << endl;

	return 0;

}
