#include "Simpson.h"
#include "Benchmark/Timer.h"

namespace NumericalMethods::Integrals {
	double simpson(const double x0, const double xn, const uint32_t n, double (*function)(double)) {
		PROFILE_CORE_FUNCTION();
		double result = 0.;
		double h = (xn - x0) / n;

		double xi = 0.;
		double temp = 0.;

		for (uint32_t i = 1; i <= n; i++) {
			xi = x0 + i * h;
			temp += function(xi - h * .5);
			if (i < n) {
				result += function(xi);
			}
		}

		result = h / 6 * (function(x0) + function(xn) + 2 * result + 4 * temp);

		return result;
	}

	double simpson(const double a, const double b, const double h, double (*function)(double)) {
		PROFILE_CORE_FUNCTION();
		double result = 0.;

		double xi = 0.;
		double temp = 0.;

		for (double i = a; i <= b; i += h) {
			xi = i + h;
			temp += function(xi - h * .5);
			if (i < b) {
				result += function(xi);
			}
		}

		result = h / 6 * (function(a) + function(b) + 2 * result + 4 * temp);

		return result;
	}
} // namespace NumericalMethods::Integrals
