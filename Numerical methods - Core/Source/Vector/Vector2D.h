#pragma once
#include "Vector.h"

namespace NumericalMethods::Vector
{
	class Vector2D : public Vector
	{
	public:
		Vector2D(double x = 0., double y = 0.);
		~Vector2D();

		void Normalize() override;
		double GetLength() const override;
		Vector2D GetNormalized() const;

		// Podstawowe operacje matematyczne
		Vector2D operator+(const Vector2D& vector);
		Vector2D operator-(const Vector2D& vector);
		Vector2D operator*(double number);	// Mnozenie przez skalar z prawej strony
		Vector2D operator/(double number);	// Dzielenie przez skalar z prawej strony

		// Iloczyn skalarny
		friend double DotProduct(const Vector2D& a, const Vector2D& b);

		// Wypisanie na ekran
		friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);

	private:
		double m_X, m_Y;
	};

	double DotProduct(const Vector2D& a, const Vector2D& b);
	std::ostream& operator<<(std::ostream& os, const Vector2D& vector);
} // namespace NumericalMethods::Vector