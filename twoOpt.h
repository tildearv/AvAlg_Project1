#ifndef __TwoOpt_H_INCLUDED__
#define __TwoOpt_H_INCLUDED__
using namespace std;
#include "NearestNeighbor.h"
#include "Cities.h"
#include <tuple>
using namespace std;

class TwoOpt{

    public:
        TwoOpt();
        tuple<int, vector<int>> opt2(Cities &cities, vector<int> tour);
        vector<int> swap(vector<int> tour, int i, int k );
        vector<int> twoOpt(Cities &cities, double time);

    private:

        int it;
        double currentTime;
        double timeLimit;
        clock_t start;

};
#endif
