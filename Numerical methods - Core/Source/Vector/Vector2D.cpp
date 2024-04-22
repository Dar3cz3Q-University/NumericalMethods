#include "Vector2D.h"

namespace NumericalMethods::Vector {
	Vector2D::Vector2D(double x, double y) : m_X(x), m_Y(y) {};

	Vector2D::~Vector2D() {};

	void Vector2D::Normalize()
	{
		double length = GetLength();

		if (abs(length) < c_epsilon) {
			return;
		}

		m_X /= length;
		m_Y /= length;
	}

	double Vector2D::GetLength() const
	{
		return sqrt(pow(m_X, 2) + pow(m_Y, 2));
	}

	Vector2D Vector2D::GetNormalized() const
	{
		double length = GetLength();

		if (abs(length) < c_epsilon) {
			return Vector2D{};
		}

		return Vector2D(m_X / length, m_Y / length);
	}

	Vector2D Vector2D::operator+(const Vector2D& p)
	{
		return Vector2D(m_X + p.m_X, m_Y + p.m_Y);
	}

	Vector2D Vector2D::operator-(const Vector2D& p)
	{
		return Vector2D(m_X - p.m_X, m_Y - p.m_Y);
	}

	Vector2D Vector2D::operator*(double p)
	{
		return Vector2D(m_X * p, m_Y * p);
	}

	Vector2D Vector2D::operator/(double p)
	{
		return Vector2D(m_X / p, m_Y / p);
	}

	double DotProduct(const Vector2D& l, const Vector2D& p)
	{
		return l.m_X * p.m_X + l.m_Y * p.m_Y;
	}

	Vector2D Projection(Vector2D& a, Vector2D& b) {
		double value = (DotProduct(b, a) / pow(b.GetLength(), 2));
		return b * value;
	}

	std::ostream& operator<<(std::ostream& os, const Vector2D& p)
	{
		os << "[" << p.m_X << ", " << p.m_Y << "]";
		return os;
	}
} // namespace NumericalMethods::Vector