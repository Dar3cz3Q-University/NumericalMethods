#include "pch.h"
#include "LegendrePolynomial.h"

void LegendrePolynomial::calculateWeightAndRoot()
{
	for (unsigned int i = 0; i <= n; i++) {
		double root = cos(M_PI * (i - .25) / (n + .5));
		Result result = calculatePolynomialValueAndDerivative(root);

		double newtonRaphsonRatio;

		do {
			newtonRaphsonRatio = result.value / result.derivative;
			root -= newtonRaphsonRatio;
			result = calculatePolynomialValueAndDerivative(root);
		} while (fabs(newtonRaphsonRatio) > epsilon);

		this->root[i] = root;
		this->weight[i] = 2. / ((1. - root * root) * result.derivative * result.derivative);
	}
}

LegendrePolynomial::Result LegendrePolynomial::calculatePolynomialValueAndDerivative(double x)
{
	Result result(x, 0);

	double value_minus_1 = 1.;
	const double f = 1. / (x * x - 1.);

	for (unsigned int i = 2; i <= n; i++) {
		const double value = ((2 * i - 1) * x * result.value - (i - 1) * value_minus_1) / i;
		result.derivative = i * f * (x * value - result.value);

		value_minus_1 = result.value;
		result.value = value;
	}

	return result;
}
