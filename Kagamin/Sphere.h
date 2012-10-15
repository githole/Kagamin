#ifndef _KAG_SPHERE_
#define _KAG_SPHERE_

#include "Shape.h"

namespace Kag {

class Sphere : public Shape {
public:
	Point center;
	Float radius;
	
	Sphere(const Point &p, const Float radius_) : center(p), radius(radius_) {}

	BBox object_bound() const {
		return BBox(Point(-radius, -radius, -radius),
					Point(radius, radius, radius));
	}
	
	bool intersect(const Ray &ray, Intersection* intersection) {
		Vector vec = ray.org - center;
		const Float vr = dot(vec, ray.dir);
		const Float det = vr * vr - dot(vec, vec) + radius * radius;
		
		if (det < 0) {
			return false;
		} 

		const Float sqrt_det = sqrt(det);
		const Float t1 = -vr + sqrt_det;
		const Float t2 = -vr - sqrt_det;
		if (t1 >= 0 || t2 >= 0) {
			// t1 > t2‚Å‚ ‚é
			if (t1 > Epsilon<Float>()) {
				if (t2 > Epsilon<Float>()) {
					intersection->thit = t2;
				} else {
					intersection->thit = t1;
				}
				return true;
			}
		}
		return false;
	}
};

};

#endif