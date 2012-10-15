#ifndef _KAG_RAY_
#define _KAG_RAY_

#include <assert.h>
#include <limits>

#include "Utility.h"
#include "Point.h"
#include "Vector.h"

namespace Kag {

template <class Type>
class Ray3D {
public:
	Point3D<Type>  org;
	Vector3D<Type> dir;
	
	Ray3D(const Point3D<Type> &origin, const Vector3D<Type> &direction) :
	org(origin), dir(direction) {}

	Point3D<Type> operator()(Type t) const {
		return org + dir * t;
	}
};

typedef Ray3D<Float> Ray;

};

#endif