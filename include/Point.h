#ifndef POINT_H
#define POINT_H

#include <sstream>

class Point3D {
public:
	Point3D();
	Point3D(double x, double y, double z);

	double GetX() const;
	double GetY() const;
	double GetZ() const;

	Point3D operator+(const Point3D& other) const;

private:
	double x_;
	double y_;
	double z_;
};

std::ostream& operator <<(std::ostream& output, const Point3D& point);

#endif // !POINT_H
