#pragma once
#include "Numerical_Methods.h"

static void zadanie1() {
    double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

    std::cout << "w[-4] = " << NumericalMethods::horner(-4, a, 4) << std::endl;
    std::cout << "w[-1] = " << NumericalMethods::horner(-1, a, 4) << std::endl;
}