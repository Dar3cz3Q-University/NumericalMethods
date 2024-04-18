#pragma once
#include <iostream>
#include <cmath>
#include "Numerical_Methods.h"

namespace NumericalMethods::Vector {
	class Vector2D;
	class Vector3D;

	class Vector
	{
	public:
		Vector() {};
		virtual ~Vector() {};

		virtual void Normalize() {};
		virtual double GetLength() const { return 0.0; };
	};

	template<class T>
	bool areOrthogonal(const T& l, const T& p) { return (l * p == 0); };
} // namespace NumericalMethods::Vector