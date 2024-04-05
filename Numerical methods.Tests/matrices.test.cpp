#include "pch.h"
#include "../Numerical methods/src/Source.h"
#include "../Numerical methods/src/Matrix.h"

namespace Matrices {
	TEST(AreMatricesEqual, NotEqual) {
		int n = 3;

		double* A = new double[n * n] {
			1, -3, 4,
			0, 1, 2,
			3, 4, 5
		};

		double* B = new double[n * n] {
			1, -3, 4,
			0, -1, 2,
			3, 4, 5
		};

		EXPECT_FALSE(Matrix::areEqual(A, B, n));

		delete[] A;
		delete[] B;
	}

	TEST(AreMatricesEqual, Equal) {
		int n = 3;

		double* A = new double[n * n] {
			1, -3, 4,
			0, 1, 2,
			3, 4, 5
		};

		double* B = new double[n * n] {
			1, -3, 4,
			0, 1, 2,
			3, 4, 5
		};

		EXPECT_TRUE(Matrix::areEqual(A, B, n));

		delete[] A;
		delete[] B;
	}
	TEST(CopyMatrix, CheckIfEqual) {
		int n = 5;

		double* A = new double[n * n] {
			1, -3, 4, 6.8, 9,
			-3, 2, 4.6, 6.3, -10,
			2, -1, 2.8, -8.4, -5,
			-6, 2, 7, -0.5, -0.9,
			5, -2, -0.5, 12, -4
		};

		double* B = Matrix::copy(A, n);

		EXPECT_TRUE(Matrix::areEqual(A, B, n));

		delete[] A;
		delete[] B;
	}

	TEST(CopyMatrix, MatrixIsNullptr) {
		int n = 0;

		double* A = nullptr;

		EXPECT_FALSE(Matrix::copy(A, n));

		delete[] A;
	}

	TEST(MultiplyMatrix, CheckIfEqual) {
		int n = 3;

		double* A = new double[n * n] {
			1, 2, 3,
			4, 5, 6,
			7, 8, 9
		};

		double* B = new double[n * n] {
			9, 8, 7,
			6, 5, 4,
			3, 2, 1
		};

		double* C = new double[n * n] {
			30, 24, 18,
			84, 69, 54,
			138, 114, 90
		};

		double* D = Matrix::multiply(A, B, n);

		ASSERT_TRUE(Matrix::areEqual(C, D, n));

		delete[] A;
		delete[] B;
		delete[] C;
		delete[] D;
	}
}
