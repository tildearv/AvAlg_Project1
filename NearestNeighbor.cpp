#include <algorithm>
#include <iostream> // cout
#include <limits> // max float
#include <stdlib.h> // srand
#include <time.h> // used for random
#include <vector>

#include "NearestNeighbor.h"

using namespace std;

/* Tour  construction heuristic.  Input  is an  array  of all  cities */
/* outputs a tour.                                                    */

vector<int> nearestNeighbor(Cities cities){

    vector<int> tour;

    // take some random vertex
    srand (time(NULL));
    int thisvertex = rand() % cities.getNumCities();

    // put in the first city and delete it from cities
    tour.push_back(thisvertex);


    // some variables to keep track of best
    float best = numeric_limits<float>::max();
    int best_ind = -1;

    while( tour.size() < cities.getNumCities() ){
        for(int j=0; j < cities.getNumCities(); ++j){
            // calc distance between thisvertex and j
            if( ( find(tour.begin(), tour.end(), j) == tour.end() ) ){
                int thisdist = cities.ds(thisvertex, j);
                if (thisdist < best){
                    best = thisdist;
                    best_ind = j;
                }
            }
        }
        thisvertex = best_ind;
        tour.push_back(thisvertex);
        best = numeric_limits<float>::max();
    }
    return tour;
}
