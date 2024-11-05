#include "GramSchmidt.h"
#include <cstring>

namespace NumericalMethods::Orthonormalization
{
	// TODO: Rewrite function to use smart pointers
    double** GramSchmidt(double a, double b, uint32_t n)
	{
		PROFILE_CORE_FUNCTION();
		double** resultBase = new double* [n];
		double** standardBase = new double* [n];

		for (uint32_t i = 0; i < n; i++)
		{
			resultBase[i] = new double[n] { 0 };
			standardBase[i] = new double[n] { 0 };
		}

		for (uint32_t i = 0; i < n; i++) standardBase[i][(n - i) - 1] = 1;

		std::memcpy(resultBase[0], standardBase[0], n * sizeof(double));

		double* tempVector;

		for (uint32_t i = 1; i < n; i++)
		{
			std::memcpy(resultBase[i], standardBase[i], n * sizeof(double));

			tempVector = new double[n] { 0 };

			for (uint32_t j = 0; j < i; j++)
			{
				double coef = NumericalMethods::Polynomial::DotProductCoef(standardBase[i], resultBase[j], a, b, n);

				double* multipliedVector = new double[n] { 0 };

				memcpy(multipliedVector, resultBase[j], n * sizeof(double));

				NumericalMethods::Polynomial::Multiply(multipliedVector, coef, n);

				NumericalMethods::Polynomial::Add(tempVector, multipliedVector, n);

				delete[] multipliedVector;
			}

			NumericalMethods::Polynomial::Subtract(resultBase[i], tempVector, n);

			delete[] tempVector;
		}

		// Clean Up
		for (uint32_t i = 0; i < n; i++) delete[] standardBase[i];
		delete[] standardBase;

		return resultBase;
	}
} // namespace NumericalMethods::Orthonormalization