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
    //TODO Dodać zamianę kolejności w tabelki
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
