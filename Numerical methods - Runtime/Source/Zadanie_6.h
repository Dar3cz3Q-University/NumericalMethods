#pragma once
#include "Numerical_Methods.h"

static void zadanie6()
{
	int n = 5;
	int m = n + 1;

	// Tablica wspolczynnikow
	double* A = new double[n * n]
	{
		1, -3, 4, 6.8, 9,
		-3, 2, 4.6, 6.3, -10,
		2, -1, 2.8, -8.4, -5,
		-6, 2, 7, -0.5, -0.9,
		5, -2, -0.5, 12, -4
	};

	// Tablica wynikow
	double* b = new double[n]
	{
		74.64,
		-40.26,
		-2.32,
		12.6,
		-8.9
	};

	// Tablica obliczonych wartosci
	double* results = NumericalMethods::gauss_crout(A, b, n);

	if (results != nullptr)
	{
		// Wyświetlenie wynikow
		for (int i = 0; i < n; i++)
		{
			std::cout << "x" << i + 1 << " = " << results[i] << "\n";
		}
	}
	else
	{
		std::cout << "Mozliwe dzielenie przez 0\n";
	}

	delete[] A;
	delete[] b;
	delete[] results;
}