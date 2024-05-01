#pragma once
#include "Numerical_Methods.h"
#include "matrix/Matrix.h"

static void zadanie7()
{
	int n = 3;

	double* check;
	double* L = new double[n * n] {0};
	double* U = new double[n * n] {0};

	double* A1 = new double[n * n] 
	{
		60, 30, 20,
		30, 20, 15,
		20, 15, 12
	};
	std::cout << "Macierz A1\n";
	if (!NumericalMethods::doolittle(A1, L, U, n)) 
	{
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else 
	{
		std::cout << "Macierz gornotrojkatna:\n";
		NumericalMethods::Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		NumericalMethods::Matrix::print(L, n);
	}

	check = NumericalMethods::Matrix::multiply(L, U, n);
	std::cout << (NumericalMethods::Matrix::areEqual(A1, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

	delete[] A1;
	delete[] check;

	double* A2 = new double[n * n] 
	{
		3, 0, 1,
		0, -1, 3,
		1, 3, 0
	};
	std::cout << "\nMacierz A2\n";
	if (!NumericalMethods::doolittle(A2, L, U, n)) 
	{
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else 
	{
		std::cout << "Macierz gornotrojkatna:\n";
		NumericalMethods::Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		NumericalMethods::Matrix::print(L, n);
	}

	check = NumericalMethods::Matrix::multiply(L, U, n);
	std::cout << (NumericalMethods::Matrix::areEqual(A2, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

	delete[] A2;
	delete[] check;

	double* A3 = new double[n * n] 
	{
		2, 1, -2,
		4, 2, -1,
		6, 3, 11
	};
	std::cout << "\nMacierz A3\n";
	if (!NumericalMethods::doolittle(A3, L, U, n)) 
	{
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else 
	{
		std::cout << "Macierz gornotrojkatna:\n";
		NumericalMethods::Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		NumericalMethods::Matrix::print(L, n);
	}
	delete[] A3;

	delete[] L;
	delete[] U;
}