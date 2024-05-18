#include <iostream>
#include "complex.h"
#include "vector.h"
#include "matrix.h"


int
main(void)
{
	matrix a ({
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
	});

	std::cout << a << std::endl;
	complex d = a.det();
	std::cout << "det = "<<a.det() << std::endl;

	matrix b = {
		{ 10, 11, 12 },
		{ 13, 14, 15 },
		{ 16, 17, 18 }
	};

	std::cout << b << std::endl;

	std::cout << a+b << std::endl;
	std::cout << a%4 << std::endl;
	std::cout << a*b << std::endl;
	std::cout << b/a << std::endl;
}