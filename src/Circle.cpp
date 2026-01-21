#include "Circle.h"

Circle::Circle(long long id,
	const std::string& name,
	const Point3D& center,
	double radius)
	: Curve3D(id, name, center),
	radius_(radius)
{
	if (radius_ <= 0.0) {
		throw std::invalid_argument("Circle radius must be positive");
	}
}

Point3D Circle::GetPoint(double t) const {
	Point3D params{ radius_ * std::cos(t), radius_ * std::sin(t), 0.0 };
	return center_ + params;
}

Point3D Circle::GetFirstDerivative(double t) const {
	return { -radius_ * std::sin(t), radius_ * std::cos(t), 0.0 };
}

bool Circle::operator<(const Circle& other) const {
	return radius_ < other.radius_;
}

double Circle::GetRadius() const {
	return radius_;
}
