#include "pch.h"
#include "../Numerical methods/src/Source.h"
#include "../Numerical methods/src/LegendrePolynomial.h"

namespace Integrals {
	static double square(double x) {
		return (-5.0 * x * x + 48);
	};

	static double qubic(double x) {
		return (5 * x * x * x + 10 * x * x + x - 50);
	}

	uint32_t n = 10e7;
	uint32_t g = 8;

	const double square_result = -1218.3334;
	const double qubic_result = 173075. / 12.;
	const double sin_result = 1.1227337145396787167255031193376221428543527573853844917663127976;
	const double exp_result = 21878.052635704139913536785065243692086730024950962902085188673510;

	const double a = 5;
	const double b = 10;

	TEST(RectangleMethod, SquareFunction) {
		double result = integral_rectangleMethod(a, b, n, 0, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(RectangleMethod, QubicFunction) {
		double result = integral_rectangleMethod(a, b, n, 0, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(RectangleMethod, SinusFunction) {
		double result = integral_rectangleMethod(a, b, n, 0, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(RectangleMethod, ExponentFunction) {
		double result = integral_rectangleMethod(a, b, n, 0, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}

	TEST(TrapezeMethod, SquareFunction) {
		double result = integral_trapezeMethod(a, b, n, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(TrapezeMethod, QubicFunction) {
		double result = integral_trapezeMethod(a, b, n, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(TrapezeMethod, SinusFunction) {
		double result = integral_trapezeMethod(a, b, n, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(TrapezeMethod, ExponentFunction) {
		double result = integral_trapezeMethod(a, b, n, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}

	TEST(SimpsonMethod, SquareFunction) {
		double result = integral_simpsonMethod(a, b, n, &square);
		ASSERT_FLOAT_EQ(result, square_result) << "N: " << n;
	}

	TEST(SimpsonMethod, QubicFunction) {
		double result = integral_simpsonMethod(a, b, n, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result) << "N: " << n;
	}

	TEST(SimpsonMethod, SinusFunction) {
		double result = integral_simpsonMethod(a, b, n, &sin);
		ASSERT_FLOAT_EQ(result, sin_result) << "N: " << n;
	}

	TEST(SimpsonMethod, ExponentFunction) {
		double result = integral_simpsonMethod(a, b, n, &exp);
		ASSERT_FLOAT_EQ(result, exp_result) << "N: " << n;
	}

	TEST(GaussMethod, SquareFunction) {
		double result = integral_gaussLegendreMethod(a, b, g, &square);
		ASSERT_FLOAT_EQ(result, square_result);
	}

	TEST(GaussMethod, QubicFunction) {
		double result = integral_gaussLegendreMethod(a, b, g, &qubic);
		ASSERT_FLOAT_EQ(result, qubic_result);
	}

	TEST(GaussMethod, SinusFunction) {
		double result = integral_gaussLegendreMethod(a, b, g, &sin);
		ASSERT_FLOAT_EQ(result, sin_result);
	}

	TEST(GaussMethod, ExponentFunction) {
		double result = integral_gaussLegendreMethod(a, b, g, &exp);
		ASSERT_FLOAT_EQ(result, exp_result);
	}
}