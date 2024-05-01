#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdint>

namespace NumericalMethods
{
	class LegendrePolynomial
	{
	public:
		LegendrePolynomial() = default;
		LegendrePolynomial(uint32_t n) : m_n(n), m_weight(nullptr), m_root(nullptr)
		{
			m_weight = new double[m_n + 1];
			m_root = new double[m_n + 1];
			calculateWeightAndRoot();
		}

		~LegendrePolynomial()
		{
			if (m_weight != nullptr)
			{
				delete[] m_weight;
			}
			if (m_root != nullptr)
			{
				delete[] m_root;
			}
		}

		double* getWeight() const
		{
			return m_weight;
		}

		double* getRoot() const
		{
			return m_root;
		}

		void recalculateWeightAndRoot(uint32_t n);

	private:
		double* m_weight;
		double* m_root;
		uint32_t m_n;

		const double m_epsilon = 1e-15;

		struct Result
		{
			double m_value;
			double m_derivative;
			Result() : m_value(0), m_derivative(0) {};
			Result(double value, double derivative) : m_value(value), m_derivative(derivative) {};
		};

		void calculateWeightAndRoot();
		Result calculatePolynomialValueAndDerivative(double x);
	};
} // namespace NumericalMethods::Integrals
