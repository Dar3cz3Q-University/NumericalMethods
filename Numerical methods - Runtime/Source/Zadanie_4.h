#pragma once
#include "Numerical_Methods.h"

static void zadanie4()
{
	NumericalMethods::Point points[5];

	points[0] = NumericalMethods::Point(-2, 5);
	points[1] = NumericalMethods::Point(-1, -2);
	points[2] = NumericalMethods::Point(0, 4);
	points[3] = NumericalMethods::Point(1, -7);
	points[4] = NumericalMethods::Point(2, 2);

	std::ofstream file;
	file.open("Lagrange_Results.txt");

	for (double i = -2; i <= 2.01; i += 0.01)
	{
		double y = NumericalMethods::lagrange(points, i, 5);
		file << i << ", " << y << "\n";
	}

	file.close();
}