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

double* WspN_WspNat(const double* b, const double* x, const unsigned int n)
{
    double* a = new double[n];

    a[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        a[i] = b[i];
        for (int j = i; j < n - 1; j++) {
            a[j] -= x[i] * a[j + 1];
        }
    }

    return a;
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
