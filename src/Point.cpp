#include "Point.h"

Point3D::Point3D() : x_(0.0), y_(0.0), z_(0.0) { }

Point3D::Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Point3D::GetX() const {
	return x_;
}

double Point3D::GetY() const {
	return y_;
}

double Point3D::GetZ() const {
	return z_;
}

Point3D Point3D::operator+(const Point3D& other) const {
	return { x_ + other.x_, y_ + other.y_, z_ + other.z_ };
}

std::ostream& operator<<(std::ostream& output, const Point3D& point) {
    output << "("
        << point.GetX() << ", "
        << point.GetY() << ", "
        << point.GetZ() << ")";

    return output;
}
