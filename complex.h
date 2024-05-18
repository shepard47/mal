#pragma once

#include <iostream>
#include <cmath>

class complex
{
	float a,b;
public:
	complex(float x = 0, float y = 0) : a(x), b(y) {}
	float Re() const;
	float Im() const;
	complex operator ~ () { return complex(a,b * (-1)); }
	void operator = (const complex& z){ a=z.a; b = z.b; }
	template <typename T> void operator = (const T x){ a=x; b = 0; }

	complex operator + (complex const& z) {
		return complex(a+z.a, b+z.b);
	}

	complex operator - (complex const& z) {
		return complex(a-z.a, b-z.b);
	}

	complex operator * (complex const& z) const {
		return complex(a*z.a - b*z.b, a*z.b + b*z.a);
	}

	complex operator / (complex const& z) {
		return complex(
			(a*z.a + b*z.b)/(z.a*z.a + z.b * z.b),
			(b*z.a - a*z.b)/(z.a*z.a + z.b * z.b)
		);
	}

	void operator += (complex const& x) {
		*this = *this+x;
	}

	void operator -= (complex const& x) {
		*this = *this-x;
	}

	void operator *= (complex const& x) {
		*this = *this*x;
	}

	void operator /= (complex const& x) {
		*this = *this/x;
	}
};

complex sin(complex x);
complex cos(complex x);
complex exp(complex x);
complex log(complex x);
complex pow(complex x, complex y);
complex sqrt(complex x);
float abs(complex x);
std::ostream& operator << (std::ostream& os, complex const& x);
