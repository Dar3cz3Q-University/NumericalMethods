#pragma once
#include <cstdint>

#include "../Numerical_Methods.h"
#include "LegendrePolynomial.h"
#include "Const/KronrodNodes.h"

namespace NumericalMethods::Integrals
{
	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Gauss-Legendre.
	/// Funkcja zawsze oblicza przyblizenie przy stopniu wielomianu Legendra rownego 4
	/// </summary>
	/// <param name="w1">Wskaznik do tablicy wspolczynnikow 1 wielomianu</param>
	/// <param name="w2">Wskaznik do tablicy wspolczynnikow 2 wielomianu</param>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="h">Dokladnosc</param>
	/// <param name="w">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss_Legendre5(const double* w1, const double* w2, double x0, double xn, double h, uint32_t w);

	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Gauss-Legendre.
	/// Funkcja zawsze oblicza przyblizenie przy stopniu wielomianu Legendra rownego 4
	/// </summary>
	/// <param name="w1">Wskaznik do tablicy wspolczynnikow 1 wielomianu</param>
	/// <param name="function">Wskaznik do funkcji</param>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="h">Dokladnosc</param>
	/// <param name="w">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss_Legendre5(const double* w1, double (*function)(double), double x0, double xn, double h, uint32_t w);

	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Gauss-Legendre
	/// </summary>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="h">Dokladnosc</param>
	/// <param name="n">Stopien wielomianu Legendra</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss_Legendre(double x0, double xn, double h, uint32_t n, double (*function)(double));

	/// <summary>
	/// Funkcja obliczajaca przyblizenie podwojnych calek oznaczonych. Metoda Gauss-Legendre
	/// </summary>
	/// <param name="x0">Poczatek przedzialu calkowania dla zmiennej x</param>
	/// <param name="xn">Koniec przedzialu calkowania dla zmiennej x</param>
	/// <param name="y0">Poczatek przedzialu calkowania dla zmiennej y</param>
	/// <param name="yn">Koniec przedzialu calkowania dla zmiennej y</param>
	/// <param name="h">Dokladnosc</param>
	/// <param name="n">Stopien wielomianu Legendra</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss_Legendre(double x0, double xn, double y0, double yn, double h, uint32_t n, double (*function)(double, double));

	/// <summary>
	/// Funkcja obliczajaca przyblizenie calek oznaczonych. Metoda Gauss-Kronrod
	/// </summary>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="xn">Koniec przedzialu calkowania</param>
	/// <param name="n">Dokladnosc</param>
	/// <param name="function">Wskaznik funkcji do calkowania</param>
	/// <returns>Obliczona wartosc calki</returns>
	double gauss_Kronrod(double a, double b, uint32_t n, double (*function)(double));
} // namespace NumericalMethods::Integrals