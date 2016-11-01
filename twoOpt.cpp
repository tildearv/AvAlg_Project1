#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
#include <time.h> // timer
#include <vector>

#include "twoOpt.h"
using namespace std;


void opt2(Cities &cities, vector<int> &tour){
    for (int i = 0; i < tour.size()-2; i++){
        int a = tour[i];
        int b = tour[i+1];
        for (int k = 0; k < tour.size()-2; k++){
            if (k == i || k == i+1){
                continue;
            }

            int c = tour[k];
            int d = tour[k+1];

            /* cout << i << i+1 << k << k+1 << endl; */

            if(cities.ds(a, c) + cities.ds(b, d) <\
                    cities.ds(a, b) + cities.ds(c, d)){
                if (k<i){
                    swap(tour, k, i);
                    return;
                }
                swap(tour, i, k);
                return;
            }
        }
    }
}



vector<int> twoOpt(Cities &cities, clock_t start) {
    /* used for random */
    srand (time(NULL));
    vector<int> tour = nearestNeighbor(cities);

    int bestDistance = cities.tourDist(tour);
    vector<int> bestTour = tour;

    float timeLimit = 1.6;
    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;

    while(currentTime < timeLimit){
        opt2(cities, tour);
        int dist = cities.tourDist(tour);

        if (dist < bestDistance) {
            bestTour = tour;
            bestDistance = dist;
        }
        currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    }
    return bestTour;
}

void swap(vector<int>& tour, int i, int k ){
    /* From Wikipedia:
       1. take route[1] to route[i-1] and add in order to new_route
       2. take route[i] to route[k] and add in reverse to new_route
       3. take route[k+1] to end and add in order to new_route
    */
    reverse(tour.begin() + i, tour.begin() + k+1);
}
