#ifndef __twoOpt_H_INCLUDED__
#define __twoOpt_H_INCLUDED__
using namespace std;
#include "NearestNeighbor.h"
#include "Cities.h"
using namespace std;
vector<int> swap(vector<int>& tour, int i, int k );
vector<int> twoOpt(Cities &cities, clock_t start);
#endif
