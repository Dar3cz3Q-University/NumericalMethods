#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstdint>

#define _USE_MATH_DEFINES
#include <cmath>

namespace NumericalMethods {

struct Point {
    double x;
    double y;
    Point() : x(0), y(0){};
    Point(double x, double y) : x(x), y(y){};
};

const double c_epsilon = 1e-15;

/// <summary>
/// Funkcja obliczajaca wartosc wielomianu w postaci naturalnej dla podanego x korzystajac ze schematu Hornera
/// </summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci naturalnej</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double horner(const double x, const double *a, const uint32_t n);

/// <summary>
/// Funkcja obliczajaca wartosc wielomianu w postaci Newtona dla podanego x korzystajac ze schematu Hornera
/// </summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="xn">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double hornerN(const double x, const double *b, const double *xn, const uint32_t n);

/// <summary>
/// Funkcja konwertujaca wspolczynniki w postaci Newtona na postac naturalna
/// </summary>
/// <param name="b">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="x">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wskaznik do tablicy obliczonych wspolczynnikow</returns>
double *WspNew_WspNat(const double *b, const double *x, const uint32_t n);

/// <summary>
/// Funkcja obliczajaca interpolacje Lagranga
/// </summary>
/// <param name="nodes">Tablica zawierajacy wezly interpolacji. Wezel interpolacji to klasa Point</param>
/// <param name="x">Wartosc x dla ktorej obliczamy wartosc</param>
/// <param name="n">Liczba wezlow interpolacji</param>
/// <returns>Obliczona wartosc funkcji w punkcie x</returns>
double lagrange(const Point *nodes, const double x, const uint32_t n);

/// <summary>
/// Funkcja obliczajaca interpolacje Newtona
/// </summary>
/// <param name="nodes">Tablica zawierajacy wezly interpolacji. Wezel interpolacji to klasa Point</param>
/// <param name="n">Liczba wezlow interpolacji</param>
/// <returns>Wskaznik do tablicy obliczonych wspolczynnikow Newtona</returns>
double *newton(const Point *nodes, const uint32_t n);

/// <summary>
/// Funkcja obliczajaca eliminacje Gaussa
/// </summary>
/// <param name="A">Wskaznik do macierzy o wielkosci n * n zawierajacy wspolczynniki przy niewiadomych</param>
/// <param name="b">Wskaznik do macierzy o wielkosci n zawierajacy wartosci wynikowe</param>
/// <param name="n">Liczba niewiadomych</param>
/// <returns>Wskaznik do tablicy obliczonych wartosci</returns>
double *gauss(const double *A, const double *b, const uint32_t n);

/// <summary>
/// Funkcja obliczajaca eliminacje Gaussa korzystajaca z Pivotingu
/// </summary>
/// <param name="A">Wskaznik do macierzy o wielkosci n * n zawierajacy wspolczynniki przy niewiadomych</param>
/// <param name="b">Wskaznik do macierzy o wielkosci n zawierajacy wartosci wynikowe</param>
/// <param name="n">Liczba niewiadomych</param>
/// <returns>Wskaznik do tablicy obliczonych wartosci</returns>
double *gauss_crout(const double *A, const double *b, const uint32_t n);

/// <summary>
/// Funkcja dzielaca macierz A na dwie macierze trojkatne L i U
/// </summary>
/// <param name="A">Wskaznik do macierzy do podzielenia</param>
/// <param name="L">Wskaznik do macierzy w ktorej znajdzie sie macierz dolnotrojkatna</param>
/// <param name="U">Wskaznik do macierzy w ktorej znajdzie sie macierz gornotrojkatna</param>
/// <param name="n">Wymiar macierzy</param>
/// <returns>false jesli nie mozna wyznaczyc rozkladu w przeciwnym wypadku true</returns>
bool doolittle(const double *A, double *L, double *U, const uint32_t n);
} // namespace NumericalMethods
