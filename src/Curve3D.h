#ifndef CURVE3D_H
#define CURVE3D_H

#include <string>
#include <cmath>
#include <stdexcept>

#include "Point.h"

class Curve3D {
public:
	Curve3D(long long id, const std::string& name, const Point3D& center)
		: id_(id), name_(name), center_(center) {
	}

	long long GetId() const {
		return id_;
	}

	const std::string& GetName() const {
		return name_;
	}

	const Point3D& GetCenter() const {
		return center_;
	}

	virtual ~Curve3D() = default;
	virtual Point3D GetPoint(double t) const = 0;
	virtual Point3D GetFirstDerivative(double t) const = 0;

protected:
	long long id_;
	std::string name_;
	Point3D center_;
};

#endif // !CURVE3D_H
