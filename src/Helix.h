#ifndef HELIX_H
#define HELIX_H

#include "Curve3D.h"

constexpr double PI = 3.14159265358979323846;

class Helix : public Curve3D {
private:
	double radius_, step_;

public:
	Helix(long long id,
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

	Point3D GetPoint(double t) const override {
		Point3D params{ radius_ * std::cos(t), radius_ * std::sin(t), step_ * t / (2 * PI) };
		return center_ + params;
	}

	Point3D GetFirstDerivative(double t) const override {
		return { -radius_ * std::sin(t), radius_ * std::cos(t), step_ / (2 * PI) };
	}
};

#endif // !HELIX_H