#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve3D.h"

class Ellipse : public Curve3D {
public:
	Ellipse(long long id,
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

	Point3D GetPoint(double t) const override {
		Point3D params{ a_ * std::cos(t), b_ * std::sin(t), 0.0 };
		return center_ + params;
	}

	Point3D GetFirstDerivative(double t) const override {
		return { -a_ * std::sin(t), b_ * std::cos(t), 0.0 };
	}

private:
	double a_, b_; // a - radius along the X, b - radius along the Y
};

#endif // !ELLIPSE_H