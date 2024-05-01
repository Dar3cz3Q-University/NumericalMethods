#pragma once
#include <cstdint>

namespace NumericalMethods::Integrals
{
	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda prostokatow
	/// </summary>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="n">Dokladnosc</param>
	/// <param name="variant">Wariant metody</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double rectangle(const double x0, double xn, uint32_t n, uint32_t variant, double (*function)(double));
} // namespace NumericalMethods::Integrals