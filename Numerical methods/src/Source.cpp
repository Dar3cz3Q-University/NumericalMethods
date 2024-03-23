#include "pch.h"
#include "Source.h"

void printMatrix(const double* matrix, const unsigned int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[(i * n) + j] << "\t";
        }
        std::cout << "\n";
    }
}

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
    for (int i = 0; i < n; i++) result[i] = quotient_table[0][i];
    
    // CleanUp
    for (int i = 0; i < n; i++) delete[] quotient_table[i];

    delete[] quotient_table;

    return result;
}

double* gauss(const double* A, const double* b, const unsigned int n)
{
    // ts - zmienna do "przeskoku" w tablicy jednowymiarowej
    int ts = n + 1;
    double* AB = new double[n * ts];

    // Przepisanie danych z tablic A i b do AB
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[(i * ts) + j] = A[(i * n) + j];
        }
        AB[(i * ts) + n] = b[i];
    }

    // Etap eliminacji
    double m;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(AB[(i * ts) + i]) < eps) return nullptr;

            m = -AB[(j * ts) + i] / AB[(i * ts) + i];

            for (int k = i + 1; k <= n; k++) {
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

        if (fabs(AB[(i * ts) + i]) < eps) return nullptr;

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[(i * ts) + j] = A[(i * n) + j];
        }
        AB[(i * ts) + n] = b[i];
    }

    // Przygotowanie wektora z numerami kolumn
    for (int i = 0; i < ts; i++) w[i] = i;

    // Etap eliminacji
    double m;

    for (int i = 0; i < n - 1; i++)
    {
        int v = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(AB[(i * ts) + w[v]]) < fabs(AB[(i * ts) + w[j]])) v = j;
            std::swap(w[v], w[i]);
        }

        for (int j = i + 1; j < n; j++) {
            if (fabs(AB[(i * ts) + w[i]]) < eps) return nullptr;

            m = -AB[(j * ts) + w[i]] / AB[(i * ts) + w[i]];

            for (int k = i + 1; k <= n; k++) {
                AB[(j * ts) + w[k]] += m * AB[(i * ts) + w[k]];
            }
        }
    }

    // Etap obliczania 
    double s;
    double* x = new double[n];

    for (int i = n - 1; i >= 0; i--)
    {
        if (fabs(AB[(i * ts) + w[i]]) < eps) return nullptr;

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
    double sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[(j * n) + k] * U[(k * n) + i];
            }
            U[(j * n) + i] = A[(j * n) + i] - sum;
        }

        for (int j = i + 1; j < n; j++) {
            sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[(j * n) + k] * U[(k * n) + i];
            }

            if (fabs(U[(i * n) + i]) < eps) return false;

            L[(j * n) + i] = (A[(j * n) + i] - sum) / U[(i * n) + i];
        }

    }

    return true;
}
