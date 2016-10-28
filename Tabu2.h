#ifndef TSP_TABU_SOLVER2_H
#define TSP_TABU_SOLVER2_H

#include "NearestNeighbor.h"
#include "Cities.h"

using namespace std;
class Tabu2{
    public:
        Tabu2();
        vector<int> tabuSolve(Cities);
        void tabuMove(int, int);
        void decrementTabu();
        vector<int> twoOpt(Cities, vector<int>);
        vector<int> swap(vector<int>&, int, int);

    private:
        int size;
        int TABU_LENGTH;
        int** tabu_list;
        vector<int> init;
        int currentCost;
        vector<int> bestSolution;
 
};

#endif