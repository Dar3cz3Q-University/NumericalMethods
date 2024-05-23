#include "GramSchmidt.h"

namespace NumericalMethods::Orthonormalization
{
    double** GramSchmidt(double a, double b, uint32_t n)
	{
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
				double numerator = NumericalMethods::Integrals::gauss_Legendre5(standardBase[i], resultBase[j], a, b, 1e-5, n);
				double denominator = NumericalMethods::Integrals::gauss_Legendre5(resultBase[j], resultBase[j], a, b, 1e-5, n);
				double coef = numerator / denominator;

				for (uint32_t k = 0; k < n; k++) tempVector[k] += coef * resultBase[j][k];
			}

			for (uint32_t j = 0; j < n; j++) resultBase[i][j] -= tempVector[j];

			delete[] tempVector;
		}

		// Clean Up
		for (uint32_t i = 0; i < n; i++) delete[] standardBase[i];
		delete[] standardBase;

		return resultBase;
	}
} // namespace NumericalMethods::Orthonormalization