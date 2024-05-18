#pragma once

#include <iostream>
#include <vector>
#include "complex.h"

class vector
{
	std::vector<complex> v;
public:
	vector(const std::vector<complex>& u) : v(u) {}
	void set(const std::vector<complex>& u){v = u;}
	int dim(void) const {return v.size();}
	virtual ~vector() {}

	complex operator [] (int i) const {
		return v[i];
	}

	complex operator * (const vector& u) {
		complex res = 0;
		if(v.size() != u.dim())
			throw std::range_error("can't do dot product");
		int n = v.size();
		for(auto i = 0; i < n; ++i)
			res += ~v[i] * u[i];
		return res;
	}
};

std::ostream& operator << (std::ostream& os, vector& u);
