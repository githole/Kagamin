#ifndef _KAG_MATRIX_
#define _KAG_MATRIX_

#include <memory>
#include <string>
#include <stdlib.h>
#include "Utility.h"

namespace Kag {

template <class Type>
class Matrix4x4 {
public:
	Type m[4][4];
	
    Matrix4x4() {
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = Type(1);
        m[0][1] = m[0][2] = m[0][3] = m[1][0] =
        m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] =
        m[3][0] = m[3][1] = m[3][2] = Type(0);
    }
	Matrix4x4(Type mat[4][4]) {
		memcpy(m, mat, sizeof(mat));
	}
	Matrix4x4(Type t00, Type t01, Type t02, Type t03,
			  Type t10, Type t11, Type t12, Type t13,
			  Type t20, Type t21, Type t22, Type t23,
			  Type t30, Type t31, Type t32, Type t33) {
		m[0][0] = t00; m[0][1] = t01; m[0][2] = t02; m[0][3] = t03;
		m[1][0] = t10; m[1][1] = t11; m[1][2] = t12; m[1][3] = t13;
		m[2][0] = t20; m[2][1] = t21; m[2][2] = t22; m[2][3] = t23;
		m[3][0] = t30; m[3][1] = t31; m[3][2] = t32; m[3][3] = t33;
	}


    bool operator==(const Matrix4x4 &m2) const {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (m[i][j] != m2.m[i][j]) return false;
        return true;
    }
    bool operator!=(const Matrix4x4 &m2) const {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (m[i][j] != m2.m[i][j]) return true;
        return false;
    }
};

template<class Type>
inline Matrix4x4<Type> mul(const Matrix4x4<Type> &m1, const Matrix4x4<Type> &m2) {
    Matrix4x4<Type> r;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            r.m[i][j] = m1.m[i][0] * m2.m[0][j] +
                        m1.m[i][1] * m2.m[1][j] +
                        m1.m[i][2] * m2.m[2][j] +
                        m1.m[i][3] * m2.m[3][j];
    return r;
}
template<class Type>
inline Matrix4x4<Type> transpose(const Matrix4x4<Type> &m) {
	return Matrix4x4<Type>(m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0], 
					 m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1], 
					 m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2], 
					 m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]);
}

template<class Type1, class Type2> 
inline Vector3D<Type1> operator*(Matrix4x4<Type2> m, const Vector3D<Type1> &v) { 
	return Vector3D<Type1>(m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z, 
						   m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z, 
						   m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z);
}
template<class Type1, class Type2> 
inline Point3D<Type1> operator*(Matrix4x4<Type2> m, const Point3D<Type1> &v) { 
	return Point3D<Type1>(m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3], 
						   m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3], 
						   m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[0][3]);
}

template<class Type>
std::ostream & operator<<(std::ostream &ostr , const Matrix4x4<Type> m) {
	std::string str;
	char buf[32];
	str += "[";
	for (int i = 0; i < 4; i ++) {
		if (i > 0)
			str += "\n ";
		str += "[";
		for (int j = 0; j < 4; j ++) {
			if (j > 0)
				str += ",";
			sprintf(buf, "%f", m.m[i][j]);
			str += buf;
		}
		str += "]";
	}
	str += "]";
	return ostr << str;
}

typedef Matrix4x4<Float> Matrix;


};

#endif