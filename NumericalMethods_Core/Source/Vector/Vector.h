#pragma once
#include <iostream>
#include <cmath>
#include "Numerical_Methods.h"

namespace NumericalMethods::Vector
{
	class Vector
	{
	public:
		Vector() {};
		virtual ~Vector() {};

		virtual void Normalize() {};
		virtual double GetLength() const { return 0.0; };
	};

	template<class T>
	bool areOrthogonal(const T& a, const T& b) { return (a * b == 0); };

	template<class T>
	T Projection(T& a, T& b)
	{
		// https://en.wikipedia.org/wiki/Vector_projection
		double value = (DotProduct(b, a) / pow(b.GetLength(), 2));
		return b * value;
	}
} // namespace NumericalMethods::Vector