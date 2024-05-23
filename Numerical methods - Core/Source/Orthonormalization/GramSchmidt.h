#pragma once
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"
#include "Integrals/Gauss.h"

namespace NumericalMethods::Orthonormalization
{
	/// <summary>
	/// Funkcja ortonormalizujaca podane wektory za pomoca metody Gram-Schmidta
	/// </summary>
	/// <typeparam name="T">Vector2D, Vector3D</typeparam>
	/// <param name="v">Tablica wektorow</param>
	/// <param name="n">Ilosc wektorow</param>
	/// <returns>Wskaznik do tablicy wektorow ortonormalnych</returns>
	template<class T>
	T* GramSchmidt(const T* v, uint32_t n)
	{
		// https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process
		// TODO: Check for types that can be calculated
		T* u = new T[n];

		for (uint32_t i = 0; i < n; i++)
		{
			u[i] = v[i];

			T temp;
			for (uint32_t j = 1; j <= i; j++)
			{
				temp = temp + Projection(u[i], u[j - 1]);
			}

			u[i] = u[i] - temp;
		}

		for (uint32_t i = 0; i < n; i++)
		{
			u[i].Normalize();
		}

		return u;
	}

	/// <summary>
	/// Funkcja ortogonalizujaca baze standardowa 1, x, x^2,...  za pomoca metody Gram-Schmidta
	/// </summary>
	/// <param name="a">Poczatek przedzialu calkowania</param>
	/// <param name="b">Koniec przedzialu calkowania</param>
	/// <param name="n">Wymiar przestrzeni</param>
	/// <returns>Wskaznik do macierzy wielomianow</returns>
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

			tempVector = new double[5] { 0 };

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
