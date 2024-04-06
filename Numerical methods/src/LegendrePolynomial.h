#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class LegendrePolynomial
{
	double a;
	double b;
	double* weight;
	double* root;
	unsigned int n;
public:
	LegendrePolynomial(double a, double b, unsigned int n) : a(a), b(b), n(n), weight(nullptr), root(nullptr) {
		weight = new double[this->n + 1];
		root = new double[this->n + 1];
		calculateWeightAndRoot();
	}

	~LegendrePolynomial() {
		if (this->weight != nullptr) {
			delete[] this->weight;
		}
		if (this->root != nullptr) {
			delete[] this->root;
		}
	}

	double* getWeight() const {
		return this->weight;
	}

	double* getRoot() const {
		return this->root;
	}
private:
	const double epsilon = 1e-15;

	struct Result {
		double value;
		double derivative;
		Result() : value(0), derivative(0) {};
		Result(double value, double derivative) : value(value), derivative(derivative) {};
	};

	void calculateWeightAndRoot();
	Result calculatePolynomialValueAndDerivative(double x);
};

