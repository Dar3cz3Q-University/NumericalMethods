#pragma once
/// <summary>Funkcja obliczajaca wartosc wielomianu w postaci naturalnej dla podanego x korzystajac ze schematu Hornera</summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci naturalnej</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double horner(double x, const double* a, int n);
/// <summary>Funkcja obliczajaca wartosc wielomianu w postaci Newtona dla podanego x korzystajac ze schematu Hornera</summary>
/// <param name="x">Argument dla ktorej obliczamy wartosc wielomianu</param>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="xn">Wskaznik to tablicy wspolrzednych x punktow</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
/// <returns>Wartosc wielomianu</returns>
double hornerN(double x, const double* a, const double* xn, int n);
/// <summary>Funkcja przeliczajaca wspolczynniki wielomianu w postaci Newtona na postac naturalna</summary>
/// <param name="a">Wskaznik do tablicy wspolczynnikow w postaci Newtona</param>
/// <param name="xn">Wskaznik do tablicy wartosci x punktow</param>
/// <param name="c">Wskaznik do tablicy w ktorej znajda sie <b>obliczone</b> wspolczynniki</param>
/// <param name="n">Ilosc wspolczynnikow (stopien wielomianu + 1)</param>
void convertToNaturalCoefficients(const double* a, const double* xn, double* c, int n);