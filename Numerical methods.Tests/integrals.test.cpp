#include "pch.h"
#include "../Numerical methods/src/Source.h"

namespace Integrals {
	static double square(double x) {
		return (-5.0 * x * x + 48);
	};

	static double qubic(double x) {
		return (5 * x * x * x + 10 * x * x + x - 50);
	}

	unsigned int n = 10e6;

	const double square_result = -3655. / 3.;
	const double qubic_result = 3016. / 3.;
	const double sin_result = 1.2737;
	const double exp_result = 20.0787;

	TEST(RectangleMethod, SquareFunction) {
		double result = integral_rectangleMethod(5, 10, n, 0, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(RectangleMethod, QubicFunction) {
		double result = integral_rectangleMethod(1, 5, n, 0, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(RectangleMethod, SinusFunction) {
		double result = integral_rectangleMethod(-5, 3, n, 0, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(RectangleMethod, ExponentFunction) {
		double result = integral_rectangleMethod(-5, 3, n, 0, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}

	TEST(TrapezeMethod, SquareFunction) {
		double result = integral_trapezeMethod(5, 10, n, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(TrapezeMethod, QubicFunction) {
		double result = integral_trapezeMethod(1, 5, n, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(TrapezeMethod, SinusFunction) {
		double result = integral_trapezeMethod(-5, 3, n, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(TrapezeMethod, ExponentFunction) {
		double result = integral_trapezeMethod(-5, 3, n, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}

	TEST(SimpsonMethod, SquareFunction) {
		double result = integral_simpsonMethod(5, 10, n, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(SimpsonMethod, QubicFunction) {
		double result = integral_simpsonMethod(1, 5, n, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(SimpsonMethod, SinusFunction) {
		double result = integral_simpsonMethod(-5, 3, n, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(SimpsonMethod, ExponentFunction) {
		double result = integral_simpsonMethod(-5, 3, n, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}
}