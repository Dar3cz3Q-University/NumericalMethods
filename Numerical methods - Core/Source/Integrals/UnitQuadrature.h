#pragma once
#include <cstdint>
#include <vector>

namespace NumericalMethods::Integrals::Unit
{
	inline const std::vector<std::vector<double>> GAUSS_POINTS =
	{
		{ 0.0 },
		{ -sqrt(1.0 / 3.0), sqrt(1.0 / 3.0) },
		{ -sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0) },
		{
			-sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6.0 / 5.0)),
			-sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0)),
			sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0)),
			sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6.0 / 5.0))
		},
		{
			-(1.0 / 3.0) * sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0)),
			-(1.0 / 3.0) * sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0)),
			0.0,
			(1.0 / 3.0)* sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0)),
			(1.0 / 3.0)* sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0))
		}
	};

	inline const std::vector<std::vector<double>> GAUSS_NODES =
	{
		{ 2.0 },
		{ 1.0, 1.0 },
		{ 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 },
		{
			(18.0 - sqrt(30.0)) / 36.0,
			(18.0 + sqrt(30.0)) / 36.0,
			(18.0 + sqrt(30.0)) / 36.0,
			(18.0 - sqrt(30.0)) / 36.0
		},
		{
			(322.0 - 13.0 * sqrt(70.0)) / 900.0,
			(322.0 + 13.0 * sqrt(70.0)) / 900.0,
			128.0 / 225.0,
			(322.0 + 13.0 * sqrt(70.0)) / 900.0,
			(322.0 - 13.0 * sqrt(70.0)) / 900.0
		}
	};

	/// <summary>
	/// Funkcja obliczajaca calke w przedziale od -1 do 1
	/// </summary>
	/// <param name="n">Ilosc wezlow Legendre</param>
	/// <param name="function">Funkcja jednej zmiennej</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss(uint32_t n, double (*function)(double));

	/// <summary>
	/// Funkcja obliczajaca calke w przedziale od -1 do 1
	/// </summary>
	/// <param name="n">Ilosc wezlow Legendre</param>
	/// <param name="function">Funkcja dwoch zmiennych</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss(uint32_t n, double (*function)(double, double));
} // namespace NumericalMethods::Integrals::Unit
