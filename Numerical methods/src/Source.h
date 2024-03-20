#pragma once
#include "Point.h"

const double eps = 1e-12;

/// <summary>
/// Funkcja obliczajaca wartosc wielomianu w postaci naturalnej dla podanego x korzystajac ze schematu Hornera
/// </summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci naturalnej</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double horner(const double x, const double* a, const unsigned int n);

/// <summary>
/// Funkcja obliczajaca wartosc wielomianu w postaci Newtona dla podanego x korzystajac ze schematu Hornera
/// </summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="xn">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double hornerN(const double x, const double* b, const double* xn, const unsigned int n);

/// <summary>
/// Funkcja konwertujaca wspolczynniki w postaci Newtona na postac naturalna
/// </summary>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="x">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wskaznik do tablicy obliczonych wspolczynnikow</returns>
double* WspNew_WspNat(const double* b, const double* x, const unsigned int n);

/// <summary>
/// Funkcja obliczajaca interpolacje Lagranga
/// </summary>
/// <param name="nodes">Tablica zawierajacy wezly interpolacji. Wezel interpolacji to klasa Point</param>
/// <param name="x">Wartosc x dla ktorej obliczamy wartosc</param>
/// <param name="n">Liczba wezlow interpolacji</param>
/// <returns>Obliczona wartosc funkcji w punkcie x</returns>
double lagrange(const Point* nodes, const double x, const unsigned int n);

/// <summary>
/// Funkcja obliczajaca interpolacje Newtona
/// </summary>
/// <param name="nodes">Tablica zawierajacy wezly interpolacji. Wezel interpolacji to klasa Point</param>
/// <param name="n">Liczba wezlow interpolacji</param>
/// <returns>Wskaznik do tablicy obliczonych wspolczynnikow Newtona</returns>
double* newton(const Point* nodes, const unsigned int n);

/// <summary>
/// Funkcja obliczajaca eliminacje Gaussa
/// </summary>
/// <param name="n">liczba niewiadomych</param>
/// <param name="AB">wskaznik do macierzy o wielkosci n * (n + 1) zawierajacy </param>
/// <param name="x">wskaznik do tablicy w ktorej znajda sie obliczone wartosci</param>
/// <returns>false jesli mozliwe byloby dzielenie przez 0. W innym wypadku true</returns>
bool gauss(int n, double* AB, double* x);
