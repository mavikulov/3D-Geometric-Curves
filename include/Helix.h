#ifndef HELIX_H
#define HELIX_H

#include "Curve3D.h"

constexpr double PI = 3.14159265358979323846;

class Helix : public Curve3D {
public:
	Helix(long long id,
		const std::string& name,
		const Point3D& center,
		double radius,
		double step);

	Point3D GetPoint(double t) const override;
	Point3D GetFirstDerivative(double t) const override;

private:
	double radius_, step_;
};

#endif // !HELIX_H