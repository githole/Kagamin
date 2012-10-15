#ifndef _KAG_INTERSECTION_
#define _KAG_INTERSECTION_

#include "Utility.h"

namespace Kag {

class Primitive;

// レイとプリミティブの幾何的な交差情報
struct Intersection {
	Float thit; // 衝突距離
};

// レイとオブジェクトの交差情報
struct IntersectionInformation {
	Intersection intersection;
	Primitive* primitive; // どのプリミティブに交差したのか
};

};

#endif