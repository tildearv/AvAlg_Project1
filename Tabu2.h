
#ifndef TSP_TABU_SOLVER2_H
#define TSP_TABU_SOLVER2_H

#include "NearestNeighbor.h"
#include "Cities.h"

using namespace std;
class Tabu2{
    public:
        //Tabu2();
        vector<int> tabuSolve(Cities, clock_t);
        void addTabuList(int, int);
        void resetTabuList();
        vector<int> twoOpt(Cities, vector<int>, float);
        //vector<int> swap(vector<int>&, int, int);

    private:
        clock_t start;
        float currentTime;
        int size;
        int TABU_LENGTH;
        int** tabu_list;
        vector<int> init;
        int currentCost;
        vector<int> bestSolution;
 
};

#endif