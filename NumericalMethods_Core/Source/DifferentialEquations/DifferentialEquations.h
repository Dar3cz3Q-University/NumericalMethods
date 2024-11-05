#pragma once
#include <iostream>
#include <fstream>

namespace NumericalMethods::DifferentialEquations 
{
	/// <summary>
	/// 
	/// </summary>
	/// <param name="func"></param>
	/// <param name="dtime"></param>
	/// <param name="t0"></param>
	/// <param name="time"></param>
	/// <returns></returns>
	double Euler(double (*func)(double), double dtime, double t0, double time);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="func"></param>
	/// <param name="dtime"></param>
	/// <param name="t0"></param>
	/// <param name="time"></param>
	/// <returns></returns>
	double RungeKutta4(double (*func)(double), double dtime, double t0, double time);
} // namespace NumericalMethods::DifferentialEquations