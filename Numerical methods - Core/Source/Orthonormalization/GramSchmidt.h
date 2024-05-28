#pragma once
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"
#include "Integrals/Gauss.h"
#include "Polynomial.h"

#include "Benchmark/Timer.h"

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
	double** GramSchmidt(double a, double b, uint32_t n);
} // namespace NumericalMethods::Orthonormalization
