#include "Matrix.h"
#include <iostream>
#include "Benchmark/Timer.h"

namespace NumericalMethods::Matrix
{
	void Print(const double* matrix, uint32_t n)
	{
		if (matrix == nullptr)
		{
			std::cout << "Niepoprawny wskaznik do tablicy\n";
			return;
		}

		for (uint32_t i = 0; i < n; i++)
		{
			for (uint32_t j = 0; j < n; j++)
			{
				std::cout << matrix[(i * n) + j] << "\t";
			}
			std::cout << "\n";
		}
	}

	double* Copy(const double* matrix, uint32_t n)
	{
		if (matrix == nullptr)
		{
			std::cout << "Niepoprawny wskaznik do tablicy\n";
			return nullptr;
		}

		double* result = new double[n * n];

		for (uint32_t i = 0; i < n; i++)
		{
			for (uint32_t j = 0; j < n; j++)
			{
				result[(i * n) + j] = matrix[(i * n) + j];
			}
		}

		return result;
	}

	double* Multiply(const double* matrix1, const double* matrix2, uint32_t n)
	{
		if (matrix1 == nullptr || matrix2 == nullptr)
		{
			std::cout << "Niepoprawny wskaznik do tablicy\n";
			return nullptr;
		}

		double* result = new double[n * n] {0};
		double sum;

		for (uint32_t i = 0; i < n; i++)
		{
			for (uint32_t j = 0; j < n; j++)
			{
				sum = 0;
				for (uint32_t k = 0; k < n; k++)
				{
					sum += matrix1[(i * n) + k] * matrix2[(k * n) + j];
				}
				result[(i * n) + j] = sum;
			}
		}

		return result;
	}

	bool AreEqual(const double* matrix1, const double* matrix2, uint32_t n)
	{
		if (matrix1 == nullptr || matrix2 == nullptr)
		{
			std::cout << "Niepoprawny wskaznik do tablicy\n";
			return false;
		}

		for (uint32_t i = 0; i < n * n; i++)
		{
			if (matrix1[i] != matrix2[i])
			{
				return false;
			}
		}

		return true;
	}
} // namespace NumericalMethods::Matrix