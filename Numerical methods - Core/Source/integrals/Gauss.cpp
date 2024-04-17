#include "Gauss.h"

namespace NumericalMethods::Integrals {
	double gauss_Legendre(const double x0, const double xn, const uint32_t n, double (*function)(double)) {
		static uint32_t prev_n = n;
		static LegendrePolynomial polynomial(x0, xn, n);

		if (prev_n != n) {
			polynomial.recalculateWeightAndRoot(n);
			prev_n = n;
		}

		double* weights = polynomial.getWeight();
		double* roots = polynomial.getRoot();

		double result = 0.;
		double width = (xn - x0) * .5;
		double mean = (x0 + xn) * .5;

		for (uint32_t i = 1; i <= n; i++) {
			result += weights[i] * function(width * roots[i] + mean);
		}

		result *= width;

		return result;
	}

	double gauss_Kronrod(const double a, const double b, const uint32_t n, double(*function)(double)) {
		double kronrod{}, x{}, v{};
		double center = (b - a) * .5;
		double mean = (a + b) * .5;
		uint32_t k = static_cast<uint32_t>((2 * n + 1) * .5);

		for (uint32_t i = 0; i <= k; i++) {
			x = ((Kronrod::nodes[i] + 1) * .5) * (b - a) + a;
			v = Kronrod::weights[i] * center;
			kronrod = kronrod + v * function(x);
		}

		return kronrod;
	}
} // namespace NumericalMethods::Integrals