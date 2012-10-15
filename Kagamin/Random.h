#ifndef _KAG_RANDOM_
#define _KAG_RANDOM_

namespace Kag {


// *** XOR ShiftŒn ***
inline unsigned int xor128(unsigned int seeds[4]) { 
  unsigned int &x = seeds[0];
  unsigned int &y = seeds[1];
  unsigned int &z = seeds[2];
  unsigned int &w = seeds[3]; 
  unsigned int t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

// http://d.hatena.ne.jp/jetbead/20110912/1315844091 ‚æ‚è”qŽØ
void init_seeds_xor128(const unsigned int initial_seed, unsigned int seeds[4]){    
	unsigned int s = initial_seed;
    for(int i = 0; i <= 3; i++){
        seeds[i] = s = 1812433253U * (s ^ (s >> 30)) + (i + 1);
    }
}

inline double rand01(unsigned int seeds[4]) {
	return (double)xor128(seeds)/(UINT_MAX); 
}


};

#endif