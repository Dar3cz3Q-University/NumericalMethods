#pragma once
#include "Numerical_Methods.h"

static void zadanie5()
{
	NumericalMethods::Point points[5];

	points[0] = NumericalMethods::Point(-2, 5);
	points[1] = NumericalMethods::Point(-1, -2);
	points[2] = NumericalMethods::Point(0, 4);
	points[3] = NumericalMethods::Point(1, -2);
	points[4] = NumericalMethods::Point(2, 2);

	double* result = NumericalMethods::newton(points, 5);

	std::cout << "\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << result[i] << "\n";
	}

	delete[] result;
}