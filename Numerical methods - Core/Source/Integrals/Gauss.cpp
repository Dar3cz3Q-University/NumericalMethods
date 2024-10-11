#include "Gauss.h"
#include "Benchmark/Timer.h"
#include "Numerical_Methods.h"

namespace NumericalMethods::Integrals
{
	double gauss_Legendre5(const double* w1, const double* w2, double x0, double xn, double h, uint32_t w)
	{
		PROFILE_CORE_FUNCTION();
		static const LegendrePolynomial polynomial(4);

		double* weights = polynomial.getWeight();
		double* roots = polynomial.getRoot();

		double result{}, width{}, mean{}, x1{}, x2{};

		for (double a = x0; a <= xn; a += h)
		{
			x1 = a;
			x2 = a + h;

			width = (x2 - x1) * .5;
			mean = (x1 + x2) * .5;

			for (uint32_t j = 1; j <= 4; j++)
				result += weights[j] * horner(width * roots[j] + mean, w1, w) * horner(width * roots[j] + mean, w2, w);
		}

		result *= width;

		CORE_ASSERT(!isinf(result));

		return result;
	}

	double gauss_Legendre5(const double* w1, double(*function)(double), double x0, double xn, double h, uint32_t w)
	{
		PROFILE_CORE_FUNCTION();
		static const LegendrePolynomial polynomial(4);

		double* weights = polynomial.getWeight();
		double* roots = polynomial.getRoot();

		double result{}, width{}, mean{}, x1{}, x2{};

		for (double a = x0; a <= xn; a += h)
		{
			x1 = a;
			x2 = a + h;

			width = (x2 - x1) * .5;
			mean = (x1 + x2) * .5;

			for (uint32_t j = 1; j <= 4; j++)
				result += weights[j] * horner(width * roots[j] + mean, w1, w) * function(width * roots[j] + mean);
		}

		result *= width;

		CORE_ASSERT(!isinf(result));

		return result;
	}

	double gauss_Legendre(double x0, double xn, double h, uint32_t n, double (*function)(double))
	{
		PROFILE_CORE_FUNCTION();
		static uint32_t prev_n = n;
		static LegendrePolynomial polynomial(n);

		if (prev_n != n)
		{
			polynomial.recalculateWeightAndRoot(n);
			prev_n = n;
		}

		double* weights = polynomial.getWeight();
		double* roots = polynomial.getRoot();

		double result{}, width{}, mean{}, x1{}, x2{};

		for (double a = x0; a <= xn; a += h)
		{
			x1 = a;
			x2 = a + h;

			width = (x2 - x1) * .5;
			mean = (x1 + x2) * .5;

			for (uint32_t j = 1; j <= n; j++)
			{
				result += weights[j] * function(width * roots[j] + mean);
			}
		}

		result *= width;

		CORE_ASSERT(!isinf(result));

		return result;
	}

	double gauss_Legendre(double x0, double xn, double y0, double yn, double h, uint32_t n, double(*function)(double, double))
	{
		PROFILE_CORE_FUNCTION();
		static uint32_t prev_n = n;
		static LegendrePolynomial polynomial(n);

		if (prev_n != n)
		{
			polynomial.recalculateWeightAndRoot(n);
			prev_n = n;
		}

		double* weights = polynomial.getWeight();
		double* roots = polynomial.getRoot();

		double result{}, width_x{}, mean_x{}, width_y{}, mean_y{}, x1{}, x2{}, y1{}, y2{};

		for (double a = x0; a <= xn; a += h)
		{
			x1 = a;
			x2 = a + h;

			width_x = (x2 - x1) * .5;
			mean_x = (x1 + x2) * .5;

			for (double b = y0; b <= yn; b += h)
			{
				y1 = b;
				y2 = b + h;

				width_y = (y2 - y1) * .5;
				mean_y = (y1 + y2) * .5;

				for (uint32_t j = 1; j <= n; j++) for (uint32_t k = 1; k <= n; k++)
					result += weights[j] * weights[k] * function(width_x * roots[j] + mean_x, width_y * roots[k] + mean_y);
			}
		}

		result *= (width_x * width_y);

		CORE_ASSERT(!isinf(result));

		return result;
	}

	// TODO: Dodac dokladnosc z jaka liczymy tzn. h
	double gauss_Kronrod(double a, double b, uint32_t n, double(*function)(double))
	{
		PROFILE_CORE_FUNCTION();
		double kronrod{}, x{}, v{};
		double center = (b - a) * .5;
		double mean = (a + b) * .5;
		uint32_t k = static_cast<uint32_t>((2 * n + 1) * .5);

		for (uint32_t i = 0; i <= k; i++)
		{
			x = ((Kronrod::nodes[i] + 1) * .5) * (b - a) + a;
			v = Kronrod::weights[i] * center;
			kronrod = kronrod + v * function(x);
		}

		return kronrod;
	}
} // namespace NumericalMethods::Integrals