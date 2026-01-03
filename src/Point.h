#ifndef POINT_H
#define POINT_H

#include <sstream>

class Point3D {
	double x_;
	double y_;
	double z_;

public:
	Point3D() : x_(0.0), y_(0.0), z_(0.0) { }
	Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) { }

	double GetX() const {
		return x_;
	}

	double GetY() const {
		return y_;
	}

	double GetZ() const {
		return z_;
	}

	Point3D operator+(const Point3D& other) const {
		return { x_ + other.x_, y_ + other.y_, z_ + other.z_ };
	}
};

std::ostream& operator <<(std::ostream& output, const Point3D& point) {
	output << "(" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")";
	return output;
}

#endif // !POINT_H
