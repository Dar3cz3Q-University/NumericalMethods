#pragma once
#include "Numerical_Methods.h"

static void zadanie3()
{
	double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

	double b_r[4] = { -4.0, 5.0 / 3.0, -7.0 / 6.0, 1.0 / 2.0 };
	double xn_r[3] = { -4.0, -1.0, 0 };

	double* result = NumericalMethods::WspNew_WspNat(b_r, xn_r, 4);

	std::cout << "Poprawne wspolczynniki:\n";

	for (int i = 3; i >= 0; i--)
	{
		std::cout << a[i] << "\n";
	}

	std::cout << "Obliczone wspolczynniki:\n";

	for (int i = 0; i < 4; i++)
	{
		std::cout << result[i] << "\n";
	}

	delete[] result;
}