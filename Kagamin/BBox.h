#pragma once

#include <limits>
#include <algorithm>

#include "Utility.h"

#include "Point.h"
#include "Vector.h"

namespace Kag {

class BBox {
public:
	Point p_min, p_max;

	BBox() {
		p_min = Point(Infinity<Float>(), Infinity<Float>(), Infinity<Float>());
		p_max = Point(-Infinity<Float>(), -Infinity<Float>(), -Infinity<Float>());
	}

	BBox(const Point &p) : p_min(p), p_max(p) {}

	BBox(const Point &p1, const Point &p2) {
		p_min = Point(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
		p_max = Point(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
	}

	bool inside(const Point &pt) const {
		return (p_min.x <= pt.x && pt.x <= p_max.x &&
				p_min.y <= pt.y && pt.y <= p_max.y &&
				p_min.z <= pt.z && pt.z <= p_max.z);
	}

	Point &operator[](int i) {
		if (i == 0)
			return p_min;
		return p_max;
	}
	const Point &operator[](int i) const {
		if (i == 0)
			return p_min;
		return p_max;
	}

	void expand(Float delta) {
		Vector v(delta, delta, delta);
		p_min -= v;
		p_max += v;
	}

	float surface_area() {
		Vector d = p_max - p_min;
		return 2.0f * (d.x * d.y + d.x * d.z + d.y * d.z);
	}
	float volume() {
		Vector d = p_max - p_min;
		return d.x * d.y * d.z;
	}

	enum LongestAxis {
		AxisX,
		AxisY,
		AxisZ,
	};

	LongestAxis longest_axis() const {
		Vector diag = p_max - p_min;
		if (diag.x > diag.y && diag.x > diag.z)
			return AxisX;
		else if (diag.y > diag.z)
			return AxisY;
		else
			return AxisZ;
	}


};


inline BBox Union(const BBox &b, const Point &p) {
	BBox ret = b;
	ret.p_min.x = std::min(b.p_min.x, p.x);
	ret.p_min.y = std::min(b.p_min.y, p.y);
	ret.p_min.z = std::min(b.p_min.z, p.z);
		
	ret.p_max.x = std::max(b.p_max.x, p.x);
	ret.p_max.y = std::max(b.p_max.y, p.y);
	ret.p_max.z = std::max(b.p_max.z, p.z);

	return ret;
}

inline BBox Union(const BBox &b1, const BBox &b2) {
	BBox ret = b1;
	ret.p_min.x = std::min(b1.p_min.x, b2.p_min.x);
	ret.p_min.y = std::min(b1.p_min.y, b2.p_min.y);
	ret.p_min.z = std::min(b1.p_min.z, b2.p_min.z);
	
	ret.p_max.x = std::max(b1.p_max.x, b2.p_max.x);
	ret.p_max.y = std::max(b1.p_max.y, b2.p_max.y);
	ret.p_max.z = std::max(b1.p_max.z, b2.p_max.z);

	return ret;
}

};