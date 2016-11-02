#include <algorithm>
#include <iostream> // cout
#include <limits> // max float
#include <stdlib.h> // srand
#include <time.h> // used for random
#include <vector>

#include "NearestNeighbor.h"

using namespace std;

/* Tour  construction heuristic.  Input  is an  array  of all  cities */
/* outputs a tour.                                             */

vector<int> nearestNeighbor(Cities &cities){

    clock_t begin = clock();

    vector<int> tour;
    int N = cities.getNumCities();

    // take some random vertex
    srand (time(NULL));
    int thisvertex = rand() % cities.getNumCities();



    // some variables to keep track of best

    bool used[N];
    for(int i = 0; i < N; i++){
        used[i] = false;
    }

    // put in the first city and notified it's used
    tour.push_back(thisvertex);
    used[thisvertex] = true;

    int i = 0;
    while (tour.size() < N){
        int best_ind = -1;
        double best = 0;
        for (int j=0; j < N; j++){
            if (!used[j]){
                int thisdist = cities.ds(tour[i], j);
                if (thisdist < best || best_ind == -1){
                    best = thisdist;
                    best_ind = j;
                }
            }
        }
        tour.push_back(best_ind);
        used[best_ind] = true;
        i++;
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    /* cout<<"time after NN = "<<elapsed_secs<<endl; */
    return tour;
}
