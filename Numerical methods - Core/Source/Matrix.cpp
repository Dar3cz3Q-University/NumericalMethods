#include "Matrix.h"
#include <iostream>

namespace NumericalMethods {
namespace Matrix {
void print(const double *matrix, const unsigned int n) {
    if (matrix == nullptr) {
        std::cout << "Niepoprawny wskaznik do tablicy\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[(i * n) + j] << "\t";
        }
        std::cout << "\n";
    }
}

double *copy(const double *matrix, const unsigned int n) {
    if (matrix == nullptr) {
        std::cout << "Niepoprawny wskaznik do tablicy\n";
        return nullptr;
    }

    double *result = new double[n * n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[(i * n) + j] = matrix[(i * n) + j];
        }
    }

    return result;
}

double *multiply(const double *matrix1, const double *matrix2, const unsigned int n) {
    if (matrix1 == nullptr || matrix2 == nullptr) {
        std::cout << "Niepoprawny wskaznik do tablicy\n";
        return nullptr;
    }

    double *result = new double[n * n]{0};
    double sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matrix1[(i * n) + k] * matrix2[(k * n) + j];
            }
            result[(i * n) + j] = sum;
        }
    }

    return result;
}

bool areEqual(const double *matrix1, const double *matrix2, const unsigned int n) {
    if (matrix1 == nullptr || matrix2 == nullptr) {
        std::cout << "Niepoprawny wskaznik do tablicy\n";
        return false;
    }

    for (int i = 0; i < n * n; i++) {
        if (matrix1[i] != matrix2[i]) {
            return false;
        }
    }

    return true;
}
} // namespace Matrix
} // namespace NumericalMethods