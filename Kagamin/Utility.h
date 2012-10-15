#ifndef _KAG_UTILITY_
#define _KAG_UTILITY_

#include <limits>

namespace Kag {

typedef float Float;

template <class Type>
inline Type Infinity() { return std::numeric_limits<Type>::infinity(); }

template <class Type>
inline Type Epsilon() { return (Type)1e-5; }

template <class Type>
inline Type LargetNumber() { return (Type)1e5; }

const Float kPI = (Float)3.141592653589793238;
const Float kTwoPI = (Float)2.0 * kPI;
};

#endif