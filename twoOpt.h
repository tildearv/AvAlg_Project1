#ifndef __twoOpt_H_INCLUDED__
#define __twoOpt_H_INCLUDED__
using namespace std;
#include "NearestNeighbor.h"
#include "Cities.h"
using namespace std;
tuple<bool, vector<int>> opt2(Cities &cities, vector<int> tour);
vector<int> swap(vector<int> tour, int i, int k );
vector<int> twoOpt(Cities &cities, double time);
#endif
