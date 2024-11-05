#pragma once
#include "Numerical_Methods.h"
#include "Orthonormalization/GramSchmidt.h"

#include "Benchmark/Timer.h"

namespace NumericalMethods::Approximation 
{
	double* ApproximatePolynomial(double a, double b, double(*function)(double), uint32_t n);
} // namespace NumericalMethods::Approximation