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
		LegendrePolynomial(uint32_t n) : m_N(n), m_Weight(nullptr), m_Root(nullptr)
		{
			m_Weight = new double[m_N + 1];
			m_Root = new double[m_N + 1];
			calculateWeightAndRoot();
		}

		~LegendrePolynomial()
		{
			if (m_Weight != nullptr)
			{
				delete[] m_Weight;
			}
			if (m_Root != nullptr)
			{
				delete[] m_Root;
			}
		}

		double* getWeight() const
		{
			return m_Weight;
		}

		double* getRoot() const
		{
			return m_Root;
		}

		void recalculateWeightAndRoot(uint32_t n);

	private:
		double* m_Weight;
		double* m_Root;
		uint32_t m_N;
		const double c_Epsilon = 1e-15;
		struct Result
		{
			double Value;
			double Derivative;
			Result() : Value(0), Derivative(0) {};
			Result(double value, double derivative) : Value(value), Derivative(derivative) {};
		};
	private:
		void calculateWeightAndRoot();
		Result calculatePolynomialValueAndDerivative(double x);
	};
} // namespace NumericalMethods::Integrals
