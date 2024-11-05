#include "UnitQuadrature.h"

double NumericalMethods::Integrals::Unit::gauss(uint32_t n, double(*function)(double))
{
    double result = 0.0;

    std::vector<double> points = GAUSS_POINTS[n - 1];
    std::vector<double> nodes = GAUSS_NODES[n - 1];

    for (uint32_t i = 0; i < n; i++)
        result += nodes[i] * function(points[i]);

    return result;
}

double NumericalMethods::Integrals::Unit::gauss(uint32_t n, double(*function)(double, double))
{
    double result = 0.0;

    std::vector<double> points = GAUSS_POINTS[n - 1];
    std::vector<double> nodes = GAUSS_NODES[n - 1];

    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < n; j++)
            result += nodes[i] * nodes[j] * function(points[i], points[j]);

    return result;
}
