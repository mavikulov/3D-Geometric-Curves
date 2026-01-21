#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve3D.h"

class Circle : public Curve3D {
public:
	Circle(long long id, const std::string& name, const Point3D& center, double radius);

	Point3D GetPoint(double t) const override;
	Point3D GetFirstDerivative(double t) const override;

	double GetRadius() const;

	bool operator<(const Circle& other) const;

private:
	double radius_;
};

#endif // !CIRCLE_H
