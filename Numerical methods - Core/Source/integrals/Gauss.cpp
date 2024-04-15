#include "Gauss.h"

namespace NumericalMethods {
    namespace Integrals {
        static double gauss_Legendre(const double x0, const double xn, const uint32_t n, double (*function)(double)) {
            const LegendrePolynomial polynomial(x0, xn, n);

            double* weight = polynomial.getWeight();
            double* root = polynomial.getRoot();

            double result = 0.;
            double width = (xn - x0) * .5;
            double mean = (x0 + xn) * .5;

            for (uint32_t i = 1; i <= n; i++) {
                result += weight[i] * function(width * root[i] + mean);
            }

            result *= width;

            return result;
        }
    } // namespace Integrals
} // namespace NumericalMethods