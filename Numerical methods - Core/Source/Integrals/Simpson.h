#pragma once
#include <cstdint>

namespace NumericalMethods::Integrals
{
	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Simpsona
	/// </summary>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="n">Dokladnosc</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double simpson(double x0, double xn, uint32_t n, double (*function)(double));

	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Simpsona
	/// </summary>
	/// <param name="a">Poczatek przedzialu calkowania</param>
	/// <param name="b">Koniec przedzialu calkowania</param>
	/// <param name="h">Wielkosc podzialu</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double simpson(double a, double b, double h, double (*function)(double));
} // namespace NumericalMethods::Integrals
