#include "pch.h"
#include "Header.h"

int main(int argc, int** argv) {
	double a[4] = {1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0};

	std::cout << "w[-4] = " << horner(-4, a, 4) << std::endl;
	std::cout << "w[-1] = " << horner(-1, a, 4) << std::endl;
	
	double b[4] = {1.0 / 2.0, -7.0 / 6.0, 5.0 / 3.0, -4.0};
	double xn[3] = { 0, -1.0, -4.0 };

	std::cout << "w[0] = " << hornerN(0, b, xn, 4) << std::endl;
	std::cout << "w[2] = " << hornerN(2, b, xn, 4) << std::endl;

	double result[4]{};

	convertToNaturalCoefficients(b, xn, result, 4);

	std::cout << "Poprawne wspolczynniki:\n";

	for (auto& factor : a) {
		std::cout << factor << std::endl;
	}

	std::cout << "Obliczone wspolczynniki:\n";

	for (auto& factor : result) {
		std::cout << factor << std::endl;
	}

	return 0;
}