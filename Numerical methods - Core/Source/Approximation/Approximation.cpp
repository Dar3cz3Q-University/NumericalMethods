#include "Approximation.h"

double* NumericalMethods::Approximation::ApproximatePolynomial(double a, double b, double(*function)(double), uint32_t n)
{
	PROFILE_CORE_FUNCTION();
	double** orthonormalBase = NumericalMethods::Orthonormalization::GramSchmidt(a, b, n);

	NumericalMethods::Polynomial::NormalizePolynomialSpace(orthonormalBase, a, b, n);

	double* alpha = new double[n] { 0 };

	for (uint32_t i = 0; i < n; i++)
		alpha[i] = NumericalMethods::Integrals::gauss_Legendre5(orthonormalBase[i], function, a, b, 1e-4, n);

	double* result = new double[n] { 0 };

	for (uint32_t i = 0; i < n; i++) for (uint32_t j = 0; j < n; j++)
		result[i] += alpha[j] * orthonormalBase[j][i];

	// Clean up
	for (uint32_t i = 0; i < n; i++) delete[] orthonormalBase[i];
	delete[] orthonormalBase;

	delete[] alpha;

	return result;
}
