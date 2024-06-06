#pragma once
#include "Numerical_Methods.h"
#include "Approximation/Approximation.h"

#include "Benchmark/Timer.h"

static double test(double x)
{
	return sin(-x) + exp(-x) - pow(x, 3);
}

static void zadanie12() 
{
	PROFILE_APP_FUNCTION();

	double a = 0.0, b = 1.0;
	uint32_t n = 5;

	double* result = NumericalMethods::Approximation::ApproximatePolynomial(a, b, &test, n);

	for (uint32_t i = n; i > 0; i--) std::cout << "\t" << "x^" << (i - 1);
	std::cout << "\n";
	for (uint32_t i = 0; i < n; i++) std::cout << result[i] << "\t";
	std::cout << "\n";

	std::ofstream file;
	file.open("Res/Approximation_Results.csv");

	for (double x = -2; x <= 2; x += 0.001) 
	{
		double w = NumericalMethods::horner(x, result, n);
		double f = test(x);
		file << x << "," << w << "," << f << "\n";
	}

	file.close();
	
	delete[] result;
}