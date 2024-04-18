#pragma once
#include "Vector.h"

namespace NumericalMethods::Vector {
	class Vector2D : public Vector {
	public:
		Vector2D(double x = 0., double y = 0.);
		~Vector2D();

		void Normalize() override;
		double GetLength() const override;
		Vector2D GetNormalized() const;

		// Podstawowe operacje matematyczne
		Vector2D operator+(const Vector2D& p);
		Vector2D operator-(const Vector2D& p);
		Vector2D operator*(const double& p);	// Mnozenie przez skalar z prawej strony
		Vector2D operator/(const double& p);	// Dzielenie przez skalar z prawej strony

		friend Vector2D operator*(const double& l, Vector2D& p);	// Mnozenie przez skalar z lewej strony
		friend Vector2D operator/(const double& l, Vector2D& p);	// Dzielenie przez skalar z lewej strony

		// Iloczyn skalarny
		friend double operator*(const Vector2D& l, const Vector2D& p);

		// Wypisanie na ekran
		friend std::ostream& operator<<(std::ostream& os, const Vector2D& p);
	private:
		double m_X, m_Y;
	};

	Vector2D operator*(const double& l, Vector2D& p);
	double operator*(const Vector2D& l, const Vector2D& p);
	std::ostream& operator<<(std::ostream& os, const Vector2D& p);
} // namespace NumericalMethods::Vector