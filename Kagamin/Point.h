#ifndef _KAG_POINT_
#define _KAG_POINT_

#include <iostream>
#include <assert.h>

#include "Vector.h"

namespace Kag {
	
template <class Type>
class Point3D {
public:
	Type x, y, z;
	Point3D() { x = y = z = Type(0); }
	Point3D(Type x_, Type y_, Type z_) : x(x_), y(y_), z(z_) {}
	
	Point3D<Type> operator+(const Point3D<Type> &v) const {
		return Point(x + v.x, y + v.y, z + v.z);
	}
	Point3D<Type> operator+(const Vector3D<Type> &v) const {
		return Point(x + v.x, y + v.y, z + v.z);
	}
	Point3D<Type> operator+=(const Vector3D<Type> &v) {
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Point3D<Type> operator-(const Vector3D<Type> &v) const {
		return Point(x - v.x, y - v.y, z - v.z);
	}
	Point3D<Type> operator-=(const Vector3D<Type> &v) {
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	Vector3D<Type> operator-(const Point3D<Type> &p) const {
		return Vector3D<Type>(x - p.x, y - p.y, z - p.z);
	}
	
	Point3D<Type> operator*(const Float f) const {
		return Point(x * f, y * f, z * f);
	}
	
	Type operator[](int i) const {
		assert(0 <= i && i <= 2);
		return (&x)[i];
	}
};

template<class Type1, class Type2> 
inline Point3D<Type1> operator*(Type2 f, const Point3D<Type1> &v) { return v * f; }

template<class Type>
inline Type Distance(const Point3D<Type> &p1, const Point3D<Type> &p2) {
	return (p1 - p2).Length();
}

template<class Type>
inline Type DistanceSquared(const Point3D<Type> &p1, const Point3D<Type> &p2) {
	return (p1 - p2).LengthSquared();
}

template<class Type>
std::ostream & operator<<(std::ostream &ostr , const Point3D<Type> p) {
	return ostr << "{" << p.x << ", " << p.y << ", " << p.z << "}";
}

typedef Point3D<Float> Point;

};

#endif