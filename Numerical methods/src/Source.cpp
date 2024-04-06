#include "pch.h"
#include "Source.h"
#include "Matrix.h"

double horner(const double x, const double* a, const unsigned int n)
{
    double result = a[0];

    for (unsigned int i = 1; i < n; i++) {
        result = result * x + a[i];
    }

    return result;
}

double hornerN(const double x, const double* b, const double* xn, const unsigned int n)
{
    double result = b[0];

    for (unsigned int i = 1; i < n; i++) {
        result = result * (x - xn[i - 1]) + b[i];
    }

    return result;
}

double* WspNew_WspNat(const double* b, const double* x, const unsigned int n)
{
    double* result = new double[n];

    result[n - 1] = b[n - 1];

    for (unsigned int i = n - 2; i >= 0; i--) {
        result[i] = b[i];
        for (unsigned int j = i; j < n - 1; j++) {
            result[j] -= x[i] * result[j + 1];
        }
    }

    return result;
}

double lagrange(const Point* nodes, const double x, const unsigned int n)
{
    double result = 0;

    for (unsigned int i = 0; i < n; i++) {
        double term = nodes[i].y;

        for (unsigned int j = 0; j < n; j++) {
            if (i != j) 
                term *= (x - nodes[j].x) / (nodes[i].x - nodes[j].x);
        }

        result += term;
    }

    return result;
}

double* newton(const Point* nodes, const unsigned int n)
{
    double* quotient_table = new double[n * n];

    for (unsigned int i = 0; i < n; i++) {
        quotient_table[(i * n)] = nodes[i].y;
    }

    for (unsigned int j = 1; j < n; j++) {
        for (unsigned int i = 0; i < n - j; i++) {
            quotient_table[(i * n) + j] = (quotient_table[((i + 1) * n) + j - 1] - quotient_table[(i * n) + j - 1]) / (nodes[i + j].x - nodes[i].x);
        }
    }

    // Copy to final table
    double* result = new double[n];
    for (unsigned int i = 0; i < n; i++) result[i] = quotient_table[i];

    delete[] quotient_table;

    return result;
}

double* gauss(const double* A, const double* b, const unsigned int n)
{
    // ts - zmienna do "przeskoku" w tablicy jednowymiarowej
    int ts = n + 1;
    double* AB = new double[n * ts];

    // Przepisanie danych z tablic A i b do AB
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            AB[(i * ts) + j] = A[(i * n) + j];
        }
        AB[(i * ts) + n] = b[i];
    }

    // Etap eliminacji
    double m;
    for (unsigned int i = 0; i < n - 1; i++)
    {
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (fabs(AB[(i * ts) + i]) < epsilon) return nullptr;

            m = -AB[(j * ts) + i] / AB[(i * ts) + i];

            for (unsigned int k = i + 1; k <= n; k++) {
                AB[(j * ts) + k] += m * AB[(i * ts) + k];
            }
        }
    }

    // Etap obliczania 
    double s;
    double* x = new double[n];
    for (int i = n - 1; i >= 0; i--)
    {
        s = AB[(i * ts) + n];

        for (int j = n - 1; j >= i + 1; j--) {
            s -= AB[(i * ts) + j] * x[j];
        }

        if (fabs(AB[(i * ts) + i]) < epsilon) return nullptr;

        x[i] = s / AB[(i * ts) + i];
    }

    // Clean Up
    delete[] AB;

    return x;
}

double* gauss_crout(const double* A, const double* b, const unsigned int n)
{
    // ts zmienna do "przeskoku" w tablicy jednowymiarowej
    int ts = n + 1;
    double* AB = new double[n * ts];
    int* w = new int[ts];

    // Przepisanie danych z tablic A i b do AB
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            AB[(i * ts) + j] = A[(i * n) + j];
        }
        AB[(i * ts) + n] = b[i];
    }

    // Przygotowanie wektora z numerami kolumn
    for (int i = 0; i < ts; i++) w[i] = i;

    // Etap eliminacji
    double m;

    for (unsigned int i = 0; i < n - 1; i++)
    {
        int v = i;
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (fabs(AB[(i * ts) + w[v]]) < fabs(AB[(i * ts) + w[j]])) v = j;
            std::swap(w[v], w[i]);
        }

        for (unsigned int j = i + 1; j < n; j++) {
            if (fabs(AB[(i * ts) + w[i]]) < epsilon) return nullptr;

            m = -AB[(j * ts) + w[i]] / AB[(i * ts) + w[i]];

            for (unsigned int k = i + 1; k <= n; k++) {
                AB[(j * ts) + w[k]] += m * AB[(i * ts) + w[k]];
            }
        }
    }

    // Etap obliczania 
    double s;
    double* x = new double[n];

    for (int i = n - 1; i >= 0; i--)
    {
        if (fabs(AB[(i * ts) + w[i]]) < epsilon) return nullptr;

        s = AB[(i * ts) + n];

        for (int j = n - 1; j >= i + 1; j--) {
            s -= AB[(i * ts) + w[j]] * x[w[j]];
        }

        x[w[i]] = s / AB[(i * ts) + w[i]];
    }

    delete[] w;
    delete[] AB;

    return x;
}

bool doolittle(const double* A, double* L, double* U, const unsigned int n)
{
    // Wypelnienie zerami
    for (unsigned int i = 0; i < n * n; i++) {
        L[i] = 0.;
        U[i] = 0.;
    }

    // Stworzenie wektora zawierajacego indeksy tablicy
    int* w = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        w[i] = i;
    }

    // Sprawdzenie diagonalnej i zamiana wierszy
    // TODO: Funkcja moze rekurencyjna ktora dobrze sprawdzi jaka ma byc kolejnosc wierszy
    for (unsigned int i = 0; i < n; i++) {
        if (A[(i * n) + i] == 0) {
            std::swap(w[i], w[i - 1]);
        }
    }

    // Obliczenie macierzy L i U
    double sum;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j <= i; j++) {
            sum = 0.;
            for (unsigned int k = 0; k < j; k++) {
                sum += L[(j * n) + k] * U[(k * n) + i];
            }
            U[(j * n) + i] = A[(w[j] * n) + i] - sum;
        }

        for (unsigned int j = i + 1; j < n; j++) {
            sum = 0.;
            for (unsigned int k = 0; k < j; k++) {
                sum += L[(j * n) + k] * U[(k * n) + i];
            }

            if (fabs(U[(i * n) + i]) < epsilon) return false;

            L[(j * n) + i] = (A[(w[j] * n) + i] - sum) / U[(i * n) + i];
        }
    }

    // Wypelnienie diagonali macierzy L jedynkami
    for (unsigned int i = 0; i < n; i++) {
        L[(i * n) + i] = 1.;
    }

    delete[] w;
      
    return true;
}

double integral_rectangleMethod(const double x0, const double xn, const unsigned int n, const unsigned int variant, double (*function)(double))
{
    double result = 0.;
    double alpha = .5;

    switch (variant) {
    case 1:
        alpha = 0.;
        break;
    case 2:
        alpha = 1.;
        break;
    default:
        break;
    }

    double h = (xn - x0) / n;
    double xi = 0.;

    for (unsigned int i = 1; i <= n; i++) {
        xi = x0 + i * h;
        result += function(xi + alpha * h);
    }

    result *= h;

    return result;
}

double integral_trapezeMethod(const double x0, const double xn, const unsigned int n, double(*function)(double))
{
    double result = 0.;
    double h = (xn - x0) / n;

    double xi = 0.;

    for (unsigned int i = 1; i <= n; i++) {
        xi = x0 + i * h;
        result += (h * .5) * (function(xi) + function(xi + h));
    }

    return result;
}

double integral_simpsonMethod(const double x0, const double xn, const unsigned int n, double(*function)(double))
{
    double result = 0.;
    double h = (xn - x0) / n;

    double xi = 0.;
    double temp = 0.;

    for (unsigned int i = 1; i <= n; i++) {
        xi = x0 + i * h;
        temp += function(xi - h * .5);
        if (i < n) {
            result += function(xi);
        }
    }

    result = h / 6 * (function(x0) + function(xn) + 2 * result + 4 * temp);

    return result;
}

double integral_gaussLegendreMethod(const double x0, const double xn, const unsigned int n, double(*function)(double))
{
    const LegendrePolynomial polynomial(x0, xn, n);

    double* weight = polynomial.getWeight();
    double* root = polynomial.getRoot();

    double result = 0.;
    double width = (xn - x0) * .5;
    double mean = (x0 + xn) * .5;

    for (unsigned int i = 1; i <= n; i++) {
        result += weight[i] * function(width * root[i] + mean);
    }

    result *= width;

    return result;
}