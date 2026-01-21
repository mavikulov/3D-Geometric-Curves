#include "Helix.h"

Helix::Helix(long long id,
			 const std::string& name,
			 const Point3D& center,
			 double radius,
			 double step) 
	   : Curve3D(id, name, center),
		 radius_(radius), step_(step)
	{
		if (radius_ <= 0.0) {
			throw std::invalid_argument("Helix radius must be positive");
		}
	}

Point3D Helix::GetPoint(double t) const {
	Point3D params{ radius_ * std::cos(t), radius_ * std::sin(t), step_ * t / (2 * PI) };
	return center_ + params;
}

Point3D Helix::GetFirstDerivative(double t) const {
	return { -radius_ * std::sin(t), radius_ * std::cos(t), step_ / (2 * PI) };
}
