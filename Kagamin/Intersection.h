#ifndef _KAG_INTERSECTION_
#define _KAG_INTERSECTION_

#include "Utility.h"

namespace Kag {

class Primitive;

// ���C�ƃv���~�e�B�u�̊􉽓I�Ȍ������
struct Intersection {
	Float thit; // �Փˋ���
};

// ���C�ƃI�u�W�F�N�g�̌������
struct IntersectionInformation {
	Intersection intersection;
	Primitive* primitive; // �ǂ̃v���~�e�B�u�Ɍ��������̂�
};

};

#endif