#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve3D.h"

class Circle : public Curve3D {
public:
	Circle(long long id,
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

	Point3D GetPoint(double t) const override {
		Point3D params{ radius_ * std::cos(t), radius_ * std::sin(t), 0.0 };
		return center_ + params;
	}

	Point3D GetFirstDerivative(double t) const override {
		return { -radius_ * std::sin(t), radius_ * std::cos(t), 0.0 };
	}

	bool operator<(const Circle& other) const {
		return radius_ < other.radius_;
	}

	double GetRadius() const {
		return radius_;
	}

private:
	double radius_;
};

#endif // !CIRCLE_H
