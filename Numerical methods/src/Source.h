#pragma once
#include "Point.h"
/// <summary>Funkcja obliczajaca wartosc wielomianu w postaci naturalnej dla podanego x korzystajac ze schematu Hornera</summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci naturalnej</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double horner(const double x, const double* a, const unsigned int n);

/// <summary>Funkcja obliczajaca wartosc wielomianu w postaci Newtona dla podanego x korzystajac ze schematu Hornera</summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="xn">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double hornerN(const double x, const double* b, const double* xn, const unsigned int n);

/// <summary>Funkcja konwertujaca wspolczynniki w postaci Newtona na postac naturalna</summary>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="x">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wskaznik do tablicy obliczonych wspolczynnikow</returns>
double* WspN_WspNat(const double* b, const double* x, const unsigned int n);

/// <summary>Funkcja obliczajaca interpolacje Lagranga</summary>
/// <param name="nodes">Tablica zawierajacy wezly interpolacji. Wezel interpolacji to klasa Point</param>
/// <param name="x">Wartosc x dla ktorej obliczamy wartosc</param>
/// <param name="n">Liczba wezlow interpolacji</param>
/// <returns>Obliczona wartosc funkcji w punkcie x</returns>
double lagrange(const Point* nodes, const double x, const unsigned int n);