#include "Trapeze.h"
#include "Benchmark/Timer.h"

namespace NumericalMethods::Integrals
{
	double trapeze(double x0, double xn, uint32_t n, double (*function)(double))
	{
		PROFILE_CORE_FUNCTION();
		double result = 0.;
		double h = (xn - x0) / n;

		double xi = 0.;

		for (uint32_t i = 1; i <= n; i++)
		{
			xi = x0 + i * h;
			result += (h * .5) * (function(xi) + function(xi + h));
		}

		return result;
	}

	double trapeze(double a, double b, double h, double (*function)(double))
	{
		PROFILE_CORE_FUNCTION();
		double result = 0.;

		double xi = 0.;

		for (double i = a; i < b; i += h)
		{
			xi = i + h;
			result += (h * .5) * (function(i) + function(xi));
		}

		return result;
	}
} // namespace NumericalMethods::Integrals