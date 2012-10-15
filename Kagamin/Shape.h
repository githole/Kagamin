#ifndef _KAG_SHAPE_
#define _KAG_SHAPE_

#include "Utility.h"
#include "Intersection.h"
#include "Ray.h"
#include "BBox.h"

namespace Kag {

// äÙâΩå`èÛ
class Shape {
public:
	const int shapeID;
	static int nextshapeID;

	Shape() : shapeID(nextshapeID++) {}

	virtual BBox object_bound() const = 0;
	virtual bool intersect(const Ray &ray, Intersection* intersection) = 0;
};

};

#endif