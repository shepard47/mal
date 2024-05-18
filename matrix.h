#pragma once

#include <iostream>
#include <vector>
#include "complex.h"

class matrix
{
	std::vector<std::vector<complex>> m;
public:
	matrix(int a = 0, int b = 0) : m(a,std::vector<complex>(b)) {
		for(int i=0; i<a; ++i)
			for(int j=0; j<b; ++j){
				if(i==j)
					m[i][j] = 1;
				else
					m[i][j] = 0;
			}
	};
	matrix(const matrix& other){m = other.m;};
	matrix(const std::vector<std::vector<complex>>& data) : m(data) {}
	matrix(std::initializer_list<std::initializer_list<complex>> in) {
		for(const auto& r : in)
			m.emplace_back(r);
	}
	virtual ~matrix(){}

	std::pair<int,int> dim(void){
		if(m.size()>0)
			return std::make_pair(m.size(),m[0].size());
		else
			throw std::range_error("nullmatrix");
	}

	void check1(matrix const& a) {
		if(m.size() != a.m.size() || m[0].size() != a.m[0].size())
			throw std::range_error("different matrices");
	}

	void check2(matrix const& a) const {
		if(m.size() != a.m[0].size() || m[0].size() != a.m.size())
			throw std::range_error("different matrices");
	}

	bool square(void) {
		if(m.size() != m[0].size())
			return false;
		else return true;
	}

	const std::vector<complex>& operator [] (int r) const {
		return m[r];
	}

	std::vector<complex>& operator [] (int r) {
		return m[r];
	}

	matrix operator = (matrix const& a) {
		matrix b;
		b.m = a.m;
		return b;
	}

	matrix operator = (std::vector<std::vector<complex>>& n) {
		return matrix(n);
	}


	matrix operator + (matrix const& a) {
		check1(a);
		int r = m.size();
		int c = m[0].size();
		std::vector<std::vector<complex>> b(r);
		for (int i = 0; i < r; ++i)
			b[i].resize(c);

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				b[i][j] = m[i][j] + a[i][j];
		return matrix(b);
	}

	matrix operator - (matrix const& a) {
		check1(a);
		int r = m.size();
		int c = m[0].size();
		std::vector<std::vector<complex>> b(r);
		for (int i = 0; i < r; ++i)
			b[i].resize(c);

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				b[i][j] = m[i][j] - a[i][j];
		return matrix(b);
	}

	matrix operator % (complex const& z) const {
		int r = m.size();
		int c = m[0].size();
		std::vector<std::vector<complex>> b(r);
		for (int i = 0; i < r; ++i)
			b[i].resize(c);

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				b[i][j] = m[i][j] * z;
		return matrix(b);
	}

	matrix operator * (matrix const& a) const {
		check2(a);
		int len = m[0].size();
		int r = m.size();
		int c = a.m[0].size();
		std::vector<std::vector<complex>> b(r);
		for (int i = 0; i < r; ++i)
			b[i].resize(c);

		for (int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				b[i][j] = 0;

		for (int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				for(int k = 0; k<len; ++k)
					b[i][j] += m[i][k] * a[k][j];
		return matrix(b);
	}

	matrix operator / (matrix const& a) {
		return (a * adj())%(complex(1,0)/det());
	}

	void operator += (matrix const& x) {
		*this = *this+x;
	}

	void operator -= (matrix const& x) {
		*this = *this-x;
	}

	void operator *= (matrix const& x) {
		*this = *this*x;
	}

	void operator /= (matrix const& x) {
		*this = *this/x;
	}

	friend std::ostream& operator << (std::ostream& os, matrix const& a);
	complex det();
	complex Tr();
	complex subdet(int a, int b);
	matrix adj();
};


