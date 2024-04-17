#pragma once
#include "Numerical_Methods.h"
#include "Integrals/Gauss.h"

#include "Benchmark/Timer.h"

double func1(double x);

static void zadanie9() {
	uint32_t n = 21;
	double a = 0.0;
	double b = 4.5;

	double correct_result = -4.402577;

	std::cout << "Gauss-Kronrod: " << NumericalMethods::Integrals::gauss_Kronrod(a, b, n, &func1) << ", correct: " << correct_result << "\n";
	std::cout << "Gauss-Legendre: " << NumericalMethods::Integrals::gauss_Legendre(a, b, n, &func1) << ", correct: " << correct_result << "\n";
}