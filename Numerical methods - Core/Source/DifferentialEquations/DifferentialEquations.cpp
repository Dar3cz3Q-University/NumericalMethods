#include "DifferentialEquations.h"

namespace NumericalMethods::DifferentialEquations 
{
	double Euler(double(*func)(double), double dtime, double t0, double time)
	{
		double result = t0;

		for (double i = dtime; i <= time; i += dtime)
		{
			// Pierwsza metoda - Euler
			//result = result + dtime * func(result);
			// Druga metoda (ulepszony Euler) - Heuna
			result = result + .5 * dtime * (func(result) + func(result + dtime * func(result)));
			// Trzecia metoda (zmodyfikowany Euler)
			//result = result + dtime * func(result + .5 * dtime * func(result));
		}

		return result;
	}

	double RungeKutta4(double(*func)(double), double dtime, double t0, double time)
	{
		double result = t0;

		for (double i = dtime; i <= time; i += dtime)
		{
			double k1 = func(result);
			double k2 = func(result + .5 * dtime * k1);
			double k3 = func(result + .5 * dtime * k2);
			double k4 = func(result + dtime * k3);

			double fi = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

			result = result + dtime * fi;
		}

		return result;
	}
} // namespace NumericalMethods::DifferentialEquations