#pragma once
#include "Numerical_Methods.h"
#include "DifferentialEquations/DifferentialEquations.h"

#include "Benchmark/Timer.h"

static double stefanBoltzmann(double t)
{
	return (-1e-12 * pow(t, 4));
}

static void zadanie13()
{
	PROFILE_APP_FUNCTION();

	double t0 = 1200.0;
	double dtime = 300.0; // seconds

	double result = NumericalMethods::DifferentialEquations::Euler(&stefanBoltzmann, 0.1, t0, dtime);
	std::cout << "Wynik Euler: " << result << "\n";

	result = NumericalMethods::DifferentialEquations::RungeKutta4(&stefanBoltzmann, 0.1, t0, dtime);
	std::cout << "Wynik Runge-Kutta: " << result << "\n";
}