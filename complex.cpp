#include "complex.h"
#include <cmath>

float complex::Re() const{
	return a;
}

float complex::Im() const{
	return b;
}
/*
complex sin(complex x)
{

}

complex cos(complex x)
{

}

complex exp(complex x)
{

}

complex log(complex x)
{

}

complex pow(complex x, complex y)
{

}

complex sqrt(complex x)
{

}
*/
float abs(complex x){
	return sqrt(x.Re()*x.Re() + x.Im()*x.Im());
}

std::ostream& operator << (std::ostream& os, complex const& x)
{
	float a = x.Re();
	float b = x.Im();

	if(b > 0)
		os << a << " + " << b << "i";
	else if(b < 0)
		os << a << " - " << -b << "i";
	else
		os << a;
	return os;
}
