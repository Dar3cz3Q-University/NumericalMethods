#include "pch.h"
#include "Source.h"
#include "Point.h"

int main(int argc, int** argv) {
	double a[4] = {1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0};

	std::cout << "w[-4] = " << horner(-4, a, 4) << std::endl;
	std::cout << "w[-1] = " << horner(-1, a, 4) << std::endl;
	
	double b[4] = {1.0 / 2.0, -7.0 / 6.0, 5.0 / 3.0, -4.0};
	double xn[3] = { 0, -1.0, -4.0 };

	std::cout << "w[0] = " << hornerN(0, b, xn, 4) << std::endl;
	std::cout << "w[2] = " << hornerN(2, b, xn, 4) << std::endl;

	double* result = WspN_WspNat(b, xn, 4);

	std::cout << "Poprawne wspolczynniki:\n";

	for (auto& factor : a) {
		std::cout << factor << std::endl;
	}

	std::cout << "Obliczone wspolczynniki:\n";

	for (int i = 0; i < 4; i++) {
		std::cout << result[i] << std::endl;
	}

	delete[] result;

	Point points[4];

	points[0] = Point(-4, 5);
	points[1] = Point(-3, 2);
	points[2] = Point(1, 5);
	points[3] = Point(2, 2);

	double y = lagrange(points, -1, 4);

	std::cout << "W(-1) = " << y << "\n";

	return 0;
}