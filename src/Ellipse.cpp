#include "Ellipse.h"

Ellipse::Ellipse(long long id,
				 const std::string& name,
				 const Point3D& center,
				 double a,
				 double b)
			  : Curve3D(id, name, center),
			    a_(a), b_(b)
{
	if ((a_ <= 0) || (b <= 0)) {
		throw std::invalid_argument("Ellipse radius must be positive");
	}
}

Point3D Ellipse::GetPoint(double t) const {
	Point3D params{ a_ * std::cos(t), b_ * std::sin(t), 0.0 };
	return center_ + params;
}

Point3D Ellipse::GetFirstDerivative(double t) const {
	return { -a_ * std::sin(t), b_ * std::cos(t), 0.0 };
}
