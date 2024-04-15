#pragma once
#include "Numerical_Methods.h"

static void zadanie2() {
    double b[4] = { 1.0 / 2.0, -7.0 / 6.0, 5.0 / 3.0, -4.0 };
    double xn[3] = { 0, -1.0, -4.0 };

    std::cout << "w[0] = " << NumericalMethods::hornerN(0, b, xn, 4) << std::endl;
    std::cout << "w[2] = " << NumericalMethods::hornerN(2, b, xn, 4) << std::endl;
}