#include "vector.h"
#include "complex.h"

std::ostream& operator << (std::ostream& os, vector& u) {
	os << "( ";
	int len = u.dim();
	for(auto i =0; i<len; ++i)
		os << u[i] << " ";
	os << ")";
	return os;
}
