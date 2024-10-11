#pragma once
#include "Numerical_Methods.h"
#include "Integrals/Gauss.h"

#include "Benchmark/Timer.h"

double func1(double x);	// x^2 * sin(x)^3
double func2(double x); // exp(x^2) * (x - 1)

void zadanie9_1() 
{
	PROFILE_APP_FUNCTION();
	std::cout << "Funkcja 1\n";

	double a = 0.0;
	double b = 4.5;

	double correct_result = -4.402577;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 2; i <= 5; i++) 
	{
		std::cout << "n: " << i << "\n";
		std::cout << "Gauss-Legendre: " << NumericalMethods::Integrals::gauss_Legendre(a, b, 10e-5, i, &func1) << "\n";
	}
}

void zadanie9_2() 
{
	PROFILE_APP_FUNCTION();
	std::cout << "Funkcja 2\n";

	double a = -2.0;
	double b = 2.0;

	double correct_result = -32.90526;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 2; i <= 5; i++) 
	{
		std::cout << "n: " << i << "\n";
		std::cout << "Gauss-Legendre: " << NumericalMethods::Integrals::gauss_Legendre(a, b, 10e-6, i, &func2) << "\n";
	}
}

void zadanie9_3() 
{
	PROFILE_APP_FUNCTION();
	std::cout << "Funkcja 3\n";

	double a = -2.0;
	double b = 2.0;

	double correct_result = 122.2095;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	// od stopnia najwyzszego do 0
	double w1[] = { 1, 2, 1, -2 };
	double w2[] = { 2, 1, -1, 10 };

	std::cout << "Gauss-Legendre dla wielomianow: " << NumericalMethods::Integrals::gauss_Legendre5(w1, w2, a, b, 10e-6, 4) << "\n";
	std::cout << "Gauss-Legendre dla wielomianow: " << NumericalMethods::Integrals::gauss_Legendre5(w1, w2, a, b, 10e-6, 4) << "\n";
}

//Grahamschmidt

static void zadanie9() 
{
	PROFILE_APP_FUNCTION();
	zadanie9_1();
	zadanie9_2();
	zadanie9_3();
}