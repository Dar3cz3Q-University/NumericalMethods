#include "Vector3D.h"

namespace NumericalMethods::Vector {
	Vector3D::Vector3D(double x, double y, double z) : m_X(x), m_Y(y), m_Z(z) {};

	Vector3D::~Vector3D() {};

	void Vector3D::Normalize()
	{
		double length = GetLength();

		if (abs(length) < c_epsilon) {
			return;
		}

		m_X /= length;
		m_Y /= length;
		m_Z /= length;
	}

	double Vector3D::GetLength() const
	{
		return sqrt(pow(m_X, 2) + pow(m_Y, 2) + pow(m_Z, 2));
	}

	Vector3D Vector3D::GetNormalized() const
	{
		double length = GetLength();

		if (abs(length) < c_epsilon) {
			return Vector3D{};
		}

		return Vector3D(m_X / length, m_Y / length, m_Z / length);
	}

	Vector3D Vector3D::operator+(const Vector3D& p)
	{
		return Vector3D(m_X + p.m_X, m_Y + p.m_Y, m_Z + p.m_Z);
	}

	Vector3D Vector3D::operator-(const Vector3D& p)
	{
		return Vector3D(m_X - p.m_X, m_Y - p.m_Y, m_Z - p.m_Z);
	}

	Vector3D Vector3D::operator*(double p)
	{
		return Vector3D(m_X * p, m_Y * p, m_Z * p);
	}

	Vector3D Vector3D::operator/(double p)
	{
		return Vector3D(m_X / p, m_Y / p, m_Z / p);
	}

	double DotProduct(const Vector3D& p, const Vector3D& l)
	{
		return p.m_X * l.m_X + p.m_Y * l.m_Y + p.m_Z * l.m_Z;
	}

	Vector3D CrossProduct(const Vector3D& a, const Vector3D& b)
	{
		double det_X = a.m_Y * b.m_Z - (a.m_Z * b.m_Y);
		double det_Y = a.m_Z * b.m_X - (a.m_X * b.m_Z);
		double det_Z = a.m_X * b.m_Y - (a.m_Y * b.m_X);

		return Vector3D(det_X, det_Y, det_Z);
	}

	Vector3D Projection(Vector3D& a, Vector3D& b)
	{
		double value = (DotProduct(b, a) / pow(b.GetLength(), 2));
		return b * value;
	}

	std::ostream& operator<<(std::ostream& os, const Vector3D& p)
	{
		os << "[" << p.m_X << ", " << p.m_Y << ", " << p.m_Z << "]";
		return os;
	}
} // namespace NumericalMethods::Vector