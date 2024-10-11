#pragma once
#include "Numerical_Methods.h"
#include "Integrals/Gauss.h"

#include "Benchmark/Timer.h"

double one_variable_function(double x)
{
	return 2.0 * pow(x, 2) + 0.1 * x + 3.0;
}

double first_two_variable_function(double x, double y)
{
	return -2.0 * pow(x, 2) * y + 2.0 * x * y + 4.0;
}

double second_two_variable_function(double x, double y)
{
	return -5.0 * pow(x, 2) * y + 2.0 * x * y + 10.0;
}

void single_variable_test()
{
	PROFILE_APP_FUNCTION();

	std::cout << "f(x) = 2x^2 + 0.1x + 3, from -1 to 1" << "\n";
	double expected_result = 7.3;
	double actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, 1e-6, 5, &one_variable_function);
	std::cout << "Expected: " << expected_result << ", Actual: " << actual_result << "\n";

	std::cout << "f(x) = 2x^2 + 0.1x + 3, from 2 to 10" << "\n";
	expected_result = 7.3;
	actual_result = NumericalMethods::Integrals::gauss_Legendre(2.0, 10.0, 1e-6, 5, &one_variable_function);
	std::cout << "Expected: " << expected_result << ", Actual: " << actual_result << "\n";
}

void multiple_variable_test()
{
	PROFILE_APP_FUNCTION();

	std::cout << "f(x, y) = -2x^2y + 2xy + 4" << "\n";
	double expected_result = 16.0;
	double actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, -1.0, 1.0, 1e-3, 3, &first_two_variable_function);
	std::cout << "Expected: " << expected_result << ", Actual: " << actual_result << "\n";

	std::cout << "f(x, y) = -5x^2y + 2xy + 10" << "\n";
	expected_result = 40.0;
	actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, -1.0, 1.0, 1e-3, 3, &second_two_variable_function);
	std::cout << "Expected: " << expected_result << ", Actual: " << actual_result << "\n";
}

void check_surface_integral()
{
	PROFILE_APP_FUNCTION();
	single_variable_test();
	multiple_variable_test();
}