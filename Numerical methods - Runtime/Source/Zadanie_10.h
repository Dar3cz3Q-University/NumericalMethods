#pragma once
#include "Numerical_Methods.h"
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"

#include "Benchmark/Timer.h"

void zadanie10() {
	PROFILE_APP_FUNCTION();
	NumericalMethods::Vector::Vector3D vec1(1, 2, 3);
	NumericalMethods::Vector::Vector3D vec2(3, 2, 1);

	NumericalMethods::Vector::Vector2D vec3(1, 5);
	NumericalMethods::Vector::Vector2D vec4(5, 1);

	std::cout << vec1.GetLength() << "\n";
	std::cout << vec1.GetNormalized() << "\n";
	std::cout << vec1 * 3 << "\n";
	std::cout << 10 * vec1 << "\n";
	std::cout << vec1 * vec2 << "\n";

	std::cout << NumericalMethods::Vector::CrossProduct(vec1, vec2) << "\n";
	std::cout << (NumericalMethods::Vector::areOrthogonal(vec3, vec4) ? "true" : "false") << "\n";
}
