#include "pch.h"
#include "LegendrePolynomial.h"

void LegendrePolynomial::calculateWeightAndRoot()
{
	for (unsigned int i = 0; i <= m_n; i++) {
		double root = cos(M_PI * (i - .25) / (m_n + .5));
		Result result = calculatePolynomialValueAndDerivative(root);

		double newtonRaphsonRatio;

		do {
			newtonRaphsonRatio = result.m_value / result.m_derivative;
			root -= newtonRaphsonRatio;
			result = calculatePolynomialValueAndDerivative(root);
		} while (fabs(newtonRaphsonRatio) > m_epsilon);

		m_root[i] = root;
		m_weight[i] = 2. / ((1. - root * root) * result.m_derivative * result.m_derivative);
	}
}

LegendrePolynomial::Result LegendrePolynomial::calculatePolynomialValueAndDerivative(double x)
{
	Result result(x, 0);

	double value_minus_1 = 1.;
	const double f = 1. / (x * x - 1.);

	for (unsigned int i = 2; i <= m_n; i++) {
		const double value = ((2 * i - 1) * x * result.m_value - (i - 1) * value_minus_1) / i;
		result.m_derivative = i * f * (x * value - result.m_value);

		value_minus_1 = result.m_value;
		result.m_value = value;
	}

	return result;
}
