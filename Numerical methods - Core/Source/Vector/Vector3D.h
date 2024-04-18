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
		Vector3D operator+(const Vector3D& p);
		Vector3D operator-(const Vector3D& p);
		Vector3D operator*(const double& p);	// Mnozenie przez skalar z prawej strony
		Vector3D operator/(const double& p);	// Dzielenie przez skalar z prawej strony 

		friend Vector3D operator*(const double& p, Vector3D& l);	// Mnozenie przez skalar z lewej strony
		friend Vector3D operator/(const double& p, Vector3D& l);	// Dzielenie przez skalar z lewej strony 

		// Iloczyn skalarny
		friend double operator*(const Vector3D& p, const Vector3D& l);

		// Iloczyn wektorowy
		friend Vector3D CrossProduct(const Vector3D& a, const Vector3D& b);

		// Wypisanie na ekran
		friend std::ostream& operator<<(std::ostream& os, const Vector3D& p);
	private:
		double m_X, m_Y, m_Z;
	};

	Vector3D operator*(const double& p, Vector3D& l);
	double operator*(const Vector3D& p, const Vector3D& l);
	Vector3D CrossProduct(const Vector3D& a, const Vector3D& b);
	std::ostream& operator<<(std::ostream& os, const Vector3D& p);
} // namespace NumericalMethods::Vector