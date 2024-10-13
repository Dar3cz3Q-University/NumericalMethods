#include "gtest/gtest.h"

#include "Integrals/Gauss.h"

double one_dimension_fixture(double x)
{
	return 2.0 * pow(x, 2) + 0.1 * x + 3.0;
}

double two_dimension_fixture(double x, double y)
{
	return -2.0 * pow(x, 2) * y + 2.0 * x * y + 4.0;
}

double second_two_dimension_fixture(double x, double y)
{
	return -5.0 * pow(x, 2) * y + 2.0 * x * y + 10.0;
}

const double EPSILON = 1e-2;
TEST(GaussLegendreTest, HandlesOneDimension) {
	// Given
	double expected_result = 7.0 + 1.0 / 3.0;
	
	// When
	double actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, 1e-6, 5, &one_dimension_fixture);

	// Then
	EXPECT_NEAR(expected_result, actual_result, EPSILON);

	// Given
	expected_result = 690.13;

	// When
	actual_result = NumericalMethods::Integrals::gauss_Legendre(2.0, 10.0, 1e-6, 5, &one_dimension_fixture);

	// Then
	EXPECT_NEAR(expected_result, actual_result, EPSILON);
}

TEST(GaussLegendreTest, HandlesTwoDimensions) {
	// Given
	double expected_result = 16.0;

	// When
	double actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, -1.0, 1.0, 1e-3, 3, &two_dimension_fixture);

	// Then
	EXPECT_NEAR(expected_result, actual_result, EPSILON);

	// Given
	expected_result = 40.0;

	// When
	actual_result = NumericalMethods::Integrals::gauss_Legendre(-1.0, 1.0, -1.0, 1.0, 1e-3, 3, &second_two_dimension_fixture);

	// Then
	EXPECT_NEAR(expected_result, actual_result, EPSILON);
}
