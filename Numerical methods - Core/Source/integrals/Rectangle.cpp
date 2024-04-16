#include "Rectangle.h"

namespace NumericalMethods::Integrals {
    double rectangle(const double x0, const double xn, const uint32_t n, const uint32_t variant, double (*function)(double)) {
        double result = 0.;
        double alpha = .5;

        switch (variant) {
        case 1:
            alpha = 0.;
            break;
        case 2:
            alpha = 1.;
            break;
        default:
            break;
        }

        double h = (xn - x0) / n;
        double xi = 0.;

        for (uint32_t i = 1; i <= n; i++) {
            xi = x0 + i * h;
            result += function(xi + alpha * h);
        }

        result *= h;

        return result;
    }
} // namespace NumericalMethods::Integrals