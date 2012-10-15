#include <iostream>

#include "Ray.h"
#include "Sphere.h"
#include "Matrix.h"
#include "Transformation.h"

int main(int argc, char **argv) {
	std::cout << "Physically Based Renderer: Kagamin" << std::endl;

	Kag::Vector v(1, 0, 0);
	Kag::Transformation t;
	t.translate(0.0, 0.0, 0.0);
	t.scale(0.5, 2.0, 1.0);

	Kag::Sphere s(Kag::Point(0, 0, 0), 1.0);

	for (int y = 0; y < 20; y ++) {
		for (int x = 0; x < 40; x ++) {
			Kag::Ray ray(Kag::Point(3.0 - 6.0 * x/40.0, 3.0 - 6.0 * y / 20.0, -2.0), Kag::Vector(0, 0, 1.0));


			Kag::Ray invray((t.getinv() * ray.org), (t.getinv() * ray.dir));


			Kag::Intersection intersection;
			if (s.intersect(invray, &intersection)) {
				std::cout << "*";
			} else std::cout << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}