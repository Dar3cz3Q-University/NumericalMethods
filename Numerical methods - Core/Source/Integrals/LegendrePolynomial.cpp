#include "LegendrePolynomial.h"
#include "Benchmark/Timer.h"

namespace NumericalMethods
{
	void LegendrePolynomial::recalculateWeightAndRoot(uint32_t n)
	{
		m_N = n;

		// Delete old data
		delete[] m_Weight;
		delete[] m_Root;

		// Create new place
		m_Weight = new double[m_N + 1];
		m_Root = new double[m_N + 1];

		calculateWeightAndRoot();
	}

	void LegendrePolynomial::calculateWeightAndRoot()
	{
		PROFILE_CORE_FUNCTION();
		for (unsigned int i = 0; i <= m_N; i++)
		{
			double root = cos(M_PI * (i - .25) / (m_N + .5));
			Result result = calculatePolynomialValueAndDerivative(root);

			double newtonRaphsonRatio;

			do
			{
				newtonRaphsonRatio = result.Value / result.Derivative;
				root -= newtonRaphsonRatio;
				result = calculatePolynomialValueAndDerivative(root);
			} while (fabs(newtonRaphsonRatio) > c_Epsilon);

			m_Root[i] = root;
			m_Weight[i] = 2. / ((1. - root * root) * result.Derivative * result.Derivative);
		}
	}

	LegendrePolynomial::Result LegendrePolynomial::calculatePolynomialValueAndDerivative(double x)
	{
		Result result(x, 0);

		double value_minus_1 = 1.;
		const double f = 1. / (x * x - 1.);

		for (unsigned int i = 2; i <= m_N; i++)
		{
			const double value = ((2 * i - 1) * x * result.Value - (i - 1) * value_minus_1) / i;
			result.Derivative = i * f * (x * value - result.Value);

			value_minus_1 = result.Value;
			result.Value = value;
		}

		return result;
	}
} // namespace NumericalMethods::Integrals