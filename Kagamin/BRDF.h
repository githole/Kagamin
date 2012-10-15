#ifndef _KAG_BRDF_
#define _KAG_BRDF_

#include "Utility.h"
namespace Kag {

enum BRDFType {
	BRDF_Transmission = 1 << 0,
};

class BRDF {
public:
	BRDFType type;
	
	/*
	virtual RGBColor f(const Vector& wi, const Vector& wo) = 0;
	virtual Float f(const Float wavelength, const Vector& wi, const Vector& wo) = 0;
	*/
//	virtual Float f_sample(const Float wavelength, const Vector& wi, const Vector& wo) = 0;
//	virtual f_sample(const BRDFChannel channel, const Vector& wi, const Vector& wo, const Sampler& sampler) = 0;
};

};

#endif