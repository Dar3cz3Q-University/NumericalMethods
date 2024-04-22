#pragma once
#include "Vector.h"

namespace NumericalMethods::Vector {
	class Vector3D : public Vector {
	public:
		Vector3D(double x = 0., double y = 0., double z = 0.);
		~Vector3D();

		void Normalize() override;
		double GetLength() const override;
		Vector3D GetNormalized() const;

		// Podstawowe operacje matematyczne
		Vector3D operator+(const Vector3D& vector);
		Vector3D operator-(const Vector3D& vector);
		Vector3D operator*(double number);	// Mnozenie przez skalar z lewej strony
		Vector3D operator/(double number);	// Dzielenie przez skalar z lewej strony 

		// Iloczyn skalarny
		friend double DotProduct(const Vector3D& a, const Vector3D& b);

		// Iloczyn wektorowy
		friend Vector3D CrossProduct(const Vector3D& a, const Vector3D& b);

		// Vector Projection
		friend Vector3D Projection(Vector3D& a, Vector3D& b);

		// Wypisanie na ekran
		friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector);
	private:
		double m_X, m_Y, m_Z;
	};

	double DotProduct(const Vector3D& a, const Vector3D& b);
	Vector3D CrossProduct(const Vector3D& a, const Vector3D& b);
	Vector3D Projection(Vector3D& a, Vector3D& b);
	std::ostream& operator<<(std::ostream& os, const Vector3D& p);
} // namespace NumericalMethods::Vector