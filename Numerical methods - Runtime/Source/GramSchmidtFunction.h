#pragma once
#include "Numerical_Methods.h"
#include "Orthonormalization/GramSchmidt.h"

#include "Benchmark/Timer.h"

static void zadanie11() {
	PROFILE_APP_FUNCTION();

	double a = 0.0, b = 1.0;
	uint32_t n = 5;

	double** result = NumericalMethods::Orthonormalization::GramSchmidt(a, b, n);

	for (uint32_t i = n; i > 0; i--) std::cout << "\t" << "x^" << (i - 1);
	std::cout << "\n";
	for (uint32_t i = 0; i < n; i++) 
	{
		std::cout << "G" << i << "\t";
		for (uint32_t j = 0; j < n; j++) 
		{
			if (result[i][j] != 0) std::cout << result[i][j];
			std::cout << "\t";
		}
		std::cout << "\n";
	}

	for (uint32_t i = 0; i < n; i++) delete result[i];
	delete result;
}