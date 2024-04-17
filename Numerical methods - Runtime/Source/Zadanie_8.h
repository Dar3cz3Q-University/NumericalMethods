#pragma once
#include "Numerical_Methods.h"
#include "Integrals/Trapeze.h"
#include "Integrals/Simpson.h"

double func1(double x) {
	return (pow(x, 2) * pow(sin(x), 3));
};

static void zadanie8_1() {
	std::cout << "Funkcja 1\n";

	double a = 0.0;
	double b = 4.5;

	double correct_result = -4.402577;

	double h = 10e-2;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "h: " << h << "\n";
		std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func1) << "\n";
		std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func1) << "\n";
		h /= 10;
	}
}

double func2(double x) {
	return ((x - 1) * exp(pow(x, 2)));
};

static void zadanie8_2() {
	std::cout << "Funkcja 2\n";

	double a = -2.0;
	double b = 2.0;

	double correct_result = -32.90526;

	double h = 10e-2;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "h: " << h << "\n";
		std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func2) << "\n";
		std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func2) << "\n";
		h /= 10;
	}
}

double func3(double x) {
	if (fabs(x) < NumericalMethods::c_epsilon) {
		return 0;
	}

	return (sin(x) / x);
};

static void zadanie8_3() {
	std::cout << "Funkcja 3\n";

	double a = 10e-6;
	double b = 1;

	double correct_result = 0.946831;

	double h = 10e-2;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "h: " << h << "\n";
		std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func3) << "\n";
		std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func3) << "\n";
		h /= 10;
	}
}

double func4(double x) {
	if (fabs(x) < NumericalMethods::c_epsilon) {
		return 0;
	}

	return (sin(1 / x));
};

static void zadanie8_4() {
	std::cout << "Funkcja 4\n";

	double a = 10e-4;
	double b = 1;

	double correct_result = 0.5040661;

	double h = 10e-2;

	std::cout << "Poprawny wynik: " << correct_result << "\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "h: " << h << "\n";
		std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func4) << "\n";
		std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func4) << "\n";
		h /= 10;
	}
}

static void zadanie8() {
	zadanie8_1();
	zadanie8_2();
	zadanie8_3();
	zadanie8_4();
}