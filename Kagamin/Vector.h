#ifndef _KAG_VECTOR_
#define _KAG_VECTOR_

#include <iostream>
#include <assert.h>

#include "Utility.h"

namespace Kag {

template <class Type>
class Vector3D {
public:
	Type x, y, z;
	Vector3D() {
		x = y = z = Type(0);
	}

	Vector3D(Type x_, Type y_, Type z_) : x(x_), y(y_), z(z_) {
	}

	Vector3D operator+(const Vector3D &v) const {
		return Vector3D(x + v.x, y + v.y, z + v.z);
	}
	Vector3D& operator+=(const Vector3D &v) {
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	Vector3D operator-(const Vector3D &v) const {
		return Vector3D(x - v.x, y - v.y, z - v.z);
	}
	Vector3D& operator-=(const Vector3D &v) {
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	Vector3D operator*(Type t) const {
		return Vector3D<Type>(t * x, t * y, t * z);
	}
	Vector3D &operator*=(Type t) {
		x *= t; y *= t; z *= t;
		return *this;
	}

	Vector3D operator/(Type t) const {
		assert(t != (Type)0.0);
		Type inv = (Type)1.0 / t;
		return Vector3D<Type>(x * inv, y * inv, z * inv);
	}

	Vector3D& operator/=(Type t) {
		assert(t != (Type)0.0);
		Type inv = (Type)1.0 / t;
		x *= inv; y *= inv; z *= inv;
		return *this;
	}

	Vector3D operator-() const { return Vector3D<Type>(-x, -y, -z); }

	Type operator[](int i) const {
		assert(0 <= i && i <= 2);
		return (&x)[i];
	}

	Type length_squared() const { return x*x + y*y + z*z; }
	Type length() const { return sqrt(LengthSquared()); }
};

template<class Type1, class Type2> 
inline Vector3D<Type1> operator*(Type2 f, const Vector3D<Type1> &v) { 
	return v * f; 
}

template<class Type>
inline Type dot(const Vector3D<Type> &v1, const Vector3D<Type> &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<class Type>
inline Type abs_dot(const Vector3D<Type> &v1, const Vector3D<Type> &v2) {
	return abs(Dot(v1, v2));
}

template<class Type>
inline Vector3D<Type> cross(const Vector3D<Type> &v1, const Vector3D<Type> &v2) {
	return Vector3D<Type>((v1.y * v2.z) - (v1.z * v2.y),
						  (v1.z * v2.x) - (v1.x * v2.z),
						  (v1.x * v2.y) - (v1.y * v2.x));
}

template<class Type>
inline Vector3D<Type> normalize(const Vector3D<Type> &v) { return v / v.Length(); }

template<class Type>
std::ostream & operator<<(std::ostream &ostr , const Vector3D<Type> v) {
	return ostr << "{" << v.x << ", " << v.y << ", " << v.z << "}";
}

template<class Type>
inline Vector3D<Type> orthogonal_vector(const Vector3D<Type> &v) {
	Type x = 0, y = 0, z = 0;
	if (abs(v.x) > Epsilon<Type>()) {
		x = (- v.y - v.z) / v.x;
		y = 1.0;
		z = 1.0;
	} else if (abs(v.y) > Epsilon<Type>()) {
		x = 1.0;
		y = (- v.x - v.z) / v.y;
		z = 1.0;
	} else if (abs(v.z) > Epsilon<Type>()) {
		x = 1.0;
		y = 1.0;
		z = (- v.x - v.y) / v.z;
	}
	
	return Normalize(Vector3D<Type>(x, y, z));
}

typedef Vector3D<Float> Vector;

};

#endif