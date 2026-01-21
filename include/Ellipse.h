#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve3D.h"

class Ellipse : public Curve3D {
public:
	Ellipse(long long id,
		const std::string& name,
		const Point3D& center,
		double a,
		double b);

	Point3D GetPoint(double t) const override;
	Point3D GetFirstDerivative(double t) const override;

private:
	double a_, b_; // a - radius along the X, b - radius along the Y
};

#endif // !ELLIPSE_H