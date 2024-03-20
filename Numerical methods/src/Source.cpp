#include "pch.h"
#include "Source.h"

double horner(const double x, const double* a, const unsigned int n)
{
    double result = a[0];

    for (int i = 1; i < n; i++) {
        result = result * x + a[i];
    }

    return result;
}

double hornerN(const double x, const double* b, const double* xn, const unsigned int n)
{
    double result = b[0];

    for (int i = 1; i < n; i++) {
        result = result * (x - xn[i - 1]) + b[i];
    }

    return result;
}

double* WspNew_WspNat(const double* b, const double* x, const unsigned int n)
{
    double* result = new double[n];

    result[n - 1] = b[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        result[i] = b[i];
        for (int j = i; j < n - 1; j++) {
            result[j] -= x[i] * result[j + 1];
        }
    }

    return result;
}

double lagrange(const Point* nodes, const double x, const unsigned int n)
{
    double result = 0;

    for (int i = 0; i < n; i++) {
        double term = nodes[i].y;

        for (int j = 0; j < n; j++) {
            if (i != j) 
                term *= (x - nodes[j].x) / (nodes[i].x - nodes[j].x);
        }

        result += term;
    }

    return result;
}

double* newton(const Point* nodes, const unsigned int n)
{
    double** quotient_table = new double*[n];

    for (int i = 0; i < n; i++) {
        quotient_table[i] = new double[n];

        quotient_table[i][0] = nodes[i].y;
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            quotient_table[i][j] = (quotient_table[i + 1][j - 1] - quotient_table[i][j - 1]) / (nodes[i + j].x - nodes[i].x);
        }
    }

    // Print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            std::cout << quotient_table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // Copy to final table
    double* result = new double[n];

    for (int i = 0; i < n; i++) {
        result[i] = quotient_table[0][i];
    }

    // CleanUp
    for (int i = 0; i < n; i++) {
        delete[] quotient_table[i];
    }

    delete[] quotient_table;

    return result;
}

bool gauss(int n, double* AB, double* x)
{
    int ts = n + 1;
    double m;

    // Etap eleminacji
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(AB[(i * ts) + i]) < eps) {
                return false;
            }

            m = -AB[(j * ts) + i] / AB[(i * ts) + i];

            // Przy k = i + 1 wynikowa tablica nie ma samych 0 a wartosci ktore pozniej nie sa brane pod uwage
            // Przy k = i widac 0
            for (int k = i; k <= n; k++) {
                AB[(j * ts) + k] += m * AB[(i * ts) + k];
            }
        }
    }

    // Wyświetlenie tablicy
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << AB[(i * ts) + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    double s;

    // Etap obliczania 
    for (int i = n - 1; i >= 0; i--)
    {
        s = AB[(i * ts) + n];

        for (int j = n - 1; j >= i + 1; j--) {
            s -= AB[(i * ts) + j] * x[j];
        }

        if (fabs(AB[(i * ts) + i]) < eps) { 
            return false; 
        }

        x[i] = s / AB[(i * ts) + i];
    }
}
