#include "matrix.h"

complex matrix::det()
{
	if(square() == false)
		throw std::range_error("not square matrix");
	int n = m.size();

	matrix l(n,n);
	matrix u(n,n);

	for (int i = 0; i < n; ++i){
		// L matrix
		for(int j=i; j < n; ++j){
			complex sum = 0;
			for(int k = 0; k < i; ++k)
				sum += l[i][k] * u[k][j];
			u[i][j] = m[i][j] - sum;
		}
		// U matrix
		for(int j=i; j < n; ++j){
			if(i==j)
				l[i][i] = 1;
			else{
				complex sum = 0;
				for(int k = 0; k < i; ++k)
					sum += l[j][i] * u[k][i];
				l[j][i] = (m[j][i] - sum) / u[i][i];	
			}
		}
	}

	complex d = 1;
	for (int i = 0; i<n;++i)
		for(int j=0; j<n; ++j)
			if(i==j)
				d *= u[i][j];


	// determinant
	return d;
}

complex matrix::subdet(int a, int b)
{
	int r = m.size()-1;
	int c = m[0].size()-1;

	matrix s(r,c);

	for(int i = 0; i<r+1; ++i){
		if(i == a)
			continue;
		for(int j=0; j<c+1; ++j){
			if(j == b)
				continue;
			if(i>a){
				if(j>b)
					s[i-1][j-1] = m[i][j];
				else
					s[i-1][j] = m[i][j];
			}else{
				if(j>b)
					s[i][j-1] = m[i][j];
				else
					s[i][j] = m[i][j];
			}
		}
	}

	return s.det();
}

complex matrix::Tr(void)
{
	int r = m.size();
	int c = m[0].size();
	complex trace = 0;
	for(auto i = 0; i < r; ++i)
		for(auto j = 0; i < c; ++j)
			if(i==j)
				trace += m[i][j];
	return trace;
}


matrix matrix::adj(void) {
		complex z= 0;
		int r = m.size();
		int c = m[0].size();
		std::vector<std::vector<complex>> b(r);
		for (int i = 0; i < r; ++i)
			b[i].resize(c);

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j){
				if(i%2 == j%2)
					b[i][j] = subdet(i,j);
				else
					b[i][j] = complex(0,0)-subdet(i,j);
			}
		return matrix(b);
	}

std::ostream& operator << (std::ostream& os, matrix const& a) {

	int r = a.m.size();
	int c = a.m[0].size();

	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j)
			os << a[i][j] << " ";
		os << std::endl;
	}
	return os;
}
