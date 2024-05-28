#pragma once
#include "Numerical_Methods.h"
#include "Integrals/Gauss.h"

namespace NumericalMethods::Polynomial 
{
	/// <summary>
	/// Funkcja wyswietlajaca wielomian
	/// </summary>
	/// <param name="a">Wskaznik do tablicy wspolczynnikow</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void Print(const double* a, uint32_t n);

	/// <summary>
	/// Funkcja dodajaca dwa wielomiany
	/// </summary>
	/// <param name="a">Wskaznik do tablicy wspolczynnikow (zostana tu zapisane wyniki)</param>
	/// <param name="b">Wskaznik do tablicy wspolczynnikow</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void Add(double* a, double* b, uint32_t n);

	/// <summary>
	/// Funkcja do odejmowania wielomianow
	/// </summary>
	/// <param name="a">Wskaznik do tablicy wspolczynnikow (zostana tu zapisane wyniki)</param>
	/// <param name="b">Wskaznik do tablicy wspolczynnikow</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void Subtract(double* a, double* b, uint32_t n);

	/// <summary>
	/// Funkcja do mnozenia wielomianow
	/// </summary>
	/// <param name="a">Wskaznik do tablicy wspolczynnikow (zostana tu zapisane wyniki)</param>
	/// <param name="b">Wskaznik do tablicy wspolczynnikow</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void Multiply(double* a, double* b, uint32_t n);

	/// <summary>
	/// Funkcja do mnozenia wielomianow przez liczbe
	/// </summary>
	/// <param name="a">Wskaznik do tablicy wspolczynnikow (zostana tu zapisane wyniki)</param>
	/// <param name="b">Liczba</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void Multiply(double* a, double b, uint32_t n);

	/// <summary>
	/// Funkcja do normalizowania przestrzeni opisanej wielomianami
	/// </summary>
	/// <param name="a">Wskaznik do macierzy wspolczynnikow wielomianow</param>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="x1">Koniec przedzialu calkowania</param>
	/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
	void NormalizePolynomialSpace(double** a, double x0, double x1, uint32_t n);

	/// <summary>
	/// Funkcja obliczajaca wspolczynnik iloczynow skalarnych dwoch wielomianow
	/// </summary>
	/// <param name="a">Wskaznik do tablicy z wspolczynnikami pierwszego wielomianu</param>
	/// <param name="b">Wskaznik do tablicy z wspolczynnikami drugiego wielomianu</param>
	/// <param name="x0">Poczatek przedzialu calkowania</param>
	/// <param name="x1">Koniec przedzialu calkowania</param>
	/// <param name="n">Wymiar przestrzeni</param>
	/// <returns>Iloczyn skalarny</returns>
	double DotProductCoef(double* a, double* b, double x0, double x1, uint32_t n);
} // namespace NumericalMethods::Polynomial

