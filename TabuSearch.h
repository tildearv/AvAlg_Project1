#ifndef TSP_TABU_SOLVER_H
#define TSP_TABU_SOLVER_H

#include "NearestNeighbor.h"
#include "Cities.h"

using namespace std;
class TabuSearch{
    public:
        TabuSearch(Cities, clock_t);
        void resetTabuList();
        vector<int> solve(Cities, clock_t, int);
        vector<int> getBestNearbySolution(int);
        vector<int> twoOpt(Cities, int);
        vector<int> swap(vector<int>&, int, int);
    private:
        float bestSolverScore;
        int** tabu_list;
        int** tabu_f_list;
        int size;
        vector<int> init;
        vector<int> solution;
        vector<int> bestSolution;
};

#endif