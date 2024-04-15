#pragma once
#include <cstdint>

namespace NumericalMethods {
	namespace Integrals {
		/// <summary>
		/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda trapezow
		/// </summary>
		/// <param name="x0">Poczatek przedzialu calkowania</param>
		/// <param name="xn">Koniec przedzialu calkowania</param>
		/// <param name="n">Dokladnosc</param>
		/// <param name="function">Wskaznik funkcji do calkowania</param>
		/// <returns>Obliczona wartosc calki</returns>
		double trapeze(const double x0, const double xn, const uint32_t n, double (*function)(double));

		/// <summary>
		/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda trapezow
		/// </summary>
		/// <param name="a">Poczatek przedzialu calkowania</param>
		/// <param name="b">Koniec przedzialu calkowania</param>
		/// <param name="h">Wielkosc podzialu</param>
		/// <param name="function">Wskaznik funkcji do calkowania</param>
		/// <returns>Obliczona wartosc calki</returns>
		double trapeze(const double a, const double b, const double h, double (*function)(double));
	} // namespace Integrals
} // namespace NumericalMethods