#pragma once
#include "Numerical_Methods.h"
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"
#include "Orthonormalization/GramSchmidt.h"

#include "Benchmark/Timer.h"

#include "Numerical_Methods.h"

#define VECTOR_TYPE NumericalMethods::Vector::Vector3D


void zadanie10() 
{
	using namespace NumericalMethods::Vector;
	using namespace NumericalMethods::Orthonormalization;

	PROFILE_APP_FUNCTION();
	int n = 3;

	VECTOR_TYPE vectors[] = { 
		VECTOR_TYPE(0, 3, 4), 
		VECTOR_TYPE(1, 0, 1), 
		VECTOR_TYPE(1, 1, 3) 
	};

	VECTOR_TYPE* basis = GramSchmidt<VECTOR_TYPE>(vectors, n);

	for (int i = 0; i < n; i++) 
	{
		std::cout << vectors[i] << "\n";
	}
	std::cout << "\n";

	for (int i = 0; i < n; i++) 
	{
		std::cout << basis[i] << "\n";
	}

	delete[] basis;
}
