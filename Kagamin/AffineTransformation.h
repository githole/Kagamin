#ifndef _KAG_AFFINE_
#define _KAG_AFFINE_

#include "Utility.h"

#include "Matrix.h"

namespace Kag {

class Transformation {
private:
	Matrix T;
	Matrix Tinv;
public:
	Matrix get() { return T; }
	Matrix getinv() { return Tinv; }

	Transformation() {
	}

	void translate(Float x, Float y, Float z) {
		T = mul(Matrix(1, 0, 0, x,
					   0, 1, 0, y,
					   0, 0, 1, z,
					   0, 0, 0, 1), T);
		Tinv = mul(Tinv, Matrix(1, 0, 0, -x,
								0, 1, 0, -y,
								0, 0, 1, -z,
								0, 0, 0,  1));
	}

	void scale(Float a, Float b, Float c) {
		T = mul(Matrix(a, 0, 0, 0,
					   0, b, 0, 0,
					   0, 0, c, 0,
					   0, 0, 0, 1), T);
		Tinv = mul(Tinv, Matrix(1/a, 0, 0, 0,
								0, 1/b, 0, 0,
								0, 0, 1/c, 0,
								0, 0, 0, 1));
	}

	void rotate_x(Float t) {
		T = mul(Matrix(1,      0,       0, 0,
					   0, cos(t), -sin(t), 0,
					   0, sin(t),  cos(t), 0,
					   0,      0,       0, 1), T);
		Tinv = mul(Tinv, Matrix(1,       0,      0, 0,
								0,  cos(t), sin(t), 0,
								0, -sin(t), cos(t), 0,
								0,       0,      0, 1));
	}
	void rotate_y(Float t) {
		T = mul(Matrix( cos(t), 0, sin(t), 0,
					         0, 1,      0, 0,
					   -sin(t), 0, cos(t), 0,
					         0, 0,      0, 1), T);
		Tinv = mul(Tinv, Matrix( cos(t), 0, -sin(t), 0,
									  0, 1,      0, 0,
								 sin(t), 0, cos(t), 0,
									  0, 0,      0, 1));
	}
	void rotate_z(Float t) {
		T = mul(Matrix( cos(t), -sin(t), 0, 0,
					    sin(t),  cos(t), 0, 0,
					         0,       0, 1, 0,
					         0,       0, 0, 1), T);
		Tinv = mul(Tinv, Matrix( cos(t), sin(t), 0, 0,
					            -sin(t), cos(t), 0, 0,
					                  0,      0, 1, 0,
					                  0,      0, 0, 1));
	}
};

};

#endif