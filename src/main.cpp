#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "CurveType.h"


std::vector<std::shared_ptr<Curve3D>> ParseFile(std::ifstream& f) {
	std::vector<std::shared_ptr<Curve3D>> result;
	size_t count;
	f >> count;
	std::string line;
	std::getline(f, line);
	for (size_t i = 1; i < count; ++i) {
		std::getline(f, line);
		std::istringstream iss(line);
		char type;
		long long id;
		iss >> type >> id;

		std::string name;
		std::getline(iss, name, '"');
		std::getline(iss, name, '"');

		double x, y, z;
		iss >> x >> y >> z;
		Point3D center{ x, y, z };

		CurveType curveType = ParseCurveType(type);
		try {
			switch (curveType) {
			case CurveType::Circle: {
				double radius;
				iss >> radius;
				result.push_back(
					std::make_shared<Circle>(id, name, center, radius)
				);
				break;
			}
			case CurveType::Ellipse: {
				double a, b;
				iss >> a >> b;
				result.push_back(
					std::make_shared<Ellipse>(id, name, center, a, b)
				);
				break;
			}
			case CurveType::Helix: {
				double radius, step;
				iss >> radius >> step;
				result.push_back(
					std::make_shared<Helix>(id, name, center, radius, step)
				);
				break;
			}
			default:
				std::cerr << "Unknown curve type: " << type << std::endl;
				break;
			}
		}

		catch (const std::exception& e) {
			std::cerr << "Error creating curve (id=" << id << "): " << e.what() << std::endl;
		}
	}
	return result;
}


int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
		return 1;
	}

	std::string filepath = argv[1];
	std::string line;
	std::ifstream file(filepath);

	if (!file.is_open()) {
		std::cerr << "Failed to open file " << filepath << std::endl;
		return 1;
	}

	std::cout << std::string(120, '-') << '\n';
	std::cout << "Task 1: Print ID, name, coordinates of points and derivatives"
				 "at t=PI/4 for each curve in the container."
			  << std::endl;
	std::vector<std::shared_ptr<Curve3D>> curves = ParseFile(file);
	constexpr double tparam = PI / 4.0;

	for (const auto& curve : curves) {
		std::cout << "Curve ID: " << curve->GetId() << ", Name = " << curve->GetName() << std::endl;
		std::cout << "Point at t = PI/4 = " << curve->GetPoint(tparam) << std::endl;
		std::cout << "Derivative at t = PI/4 = " << curve->GetFirstDerivative(tparam) << std::endl;
		std::cout << "\n";
	}

	std::cout << "\n\n";
	std::cout << std::string(120, '-') << '\n';
	std::cout << "Task 2: Sort the second container in the ascending order of circles radii."
			  << std::endl;

	std::vector<std::shared_ptr<Circle>> circles;
	for (const auto& curve : curves) {
		if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
			circles.push_back(circle);
		}
	}

	std::cout << "Circles before sorting" << std::endl;
	for (const auto& circle : circles) {
		std::cout << "\t" << circle->GetName() << ", radius = " << circle->GetRadius() << std::endl;
	}

	std::sort(circles.begin(), circles.end(),
		[](const auto& first, const auto& second) {
			return first->GetRadius() < second->GetRadius();
		});

	std::cout << "\nCircles after sorting" << std::endl;
	for (const auto& circle : circles) {
		std::cout << "\t" << circle->GetName() << ", radius = " << circle->GetRadius() << std::endl;
	}

	std::cout << "\n\n";
	std::cout << std::string(120, '-') << '\n';
	std::cout << "Task 3: Compute the total sum of radii of all curves in the second container" << std::endl;
	double sumRadius = std::accumulate(
		circles.begin(),
		circles.end(),
		0.0,
		[](double sum, const auto& circle) {
			return sum + circle->GetRadius();
		});
	std::cout << "Sum = " << sumRadius << std::endl;

    return 0;
}
