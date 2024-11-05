#include "Polynomial.h"

namespace NumericalMethods::Polynomial
{
	void Print(const double* a, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++)
		{
			if (a[i] != 0) std::cout << a[i];

			std::cout << "\t";
		}

		std::cout << "\n";
	}

	void Add(double* a, double* b, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++) a[i] += b[i];
	}

	void Subtract(double* a, double* b, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++) a[i] -= b[i];
	}

	void Multiply(double* a, double* b, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++) a[i] *= b[i];
	}

	void Multiply(double* a, double b, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++) a[i] *= b;
	}

	void NormalizePolynomialSpace(double** a, double x0, double x1, uint32_t n)
	{
		for (uint32_t i = 0; i < n; i++)
		{
			double norm = sqrt(NumericalMethods::Integrals::gauss_Legendre5(a[i], a[i], x0, x1, 1e-4, n));
			for (uint32_t j = 0; j < n; j++) a[i][j] /= norm;
		}
	}

	double DotProductCoef(double* a, double* b, double x0, double x1, uint32_t n)
	{
		double numerator = NumericalMethods::Integrals::gauss_Legendre5(a, b, x0, x1, 1e-4, n);
		double denominator = NumericalMethods::Integrals::gauss_Legendre5(b, b, x0, x1, 1e-4, n);

		return numerator / denominator;
	}
} // namespace NumericalMethods::Polynomial

