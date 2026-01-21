#include "Curve3D.h"

Curve3D::Curve3D(long long id, const std::string& name, const Point3D& center)
	: id_(id), name_(name), center_(center) {
}

long long Curve3D::GetId() const {
	return id_;
}

const std::string& Curve3D::GetName() const {
	return name_;
}

const Point3D& Curve3D::GetCenter() const {
	return center_;
}
