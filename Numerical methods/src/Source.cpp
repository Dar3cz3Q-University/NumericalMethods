#include "pch.h"
#include "Header.h"

double horner(double x, const double* a, int n)
{
    double result = a[0];

    for (int i = 1; i < n; i++) {
        result = result * x + a[i];
    }

    return result;
}

double hornerN(double x, const double* a, const double* xn, int n)
{
    double result = a[0];

    for (int i = 1; i < n; i++) {
        result = result * (x - xn[i - 1]) + a[i];
    }

    return result;
}

void convertToNaturalCoefficients(const double* a, const double* xn, double* c, int n) 
{
    
}
