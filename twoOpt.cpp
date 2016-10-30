#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
#include <time.h> // timer
#include <vector>

#include "twoOpt.h"
using namespace std;

vector<int> twoOpt(Cities &cities, clock_t start) {

    float timeLimit = 2*0.9;

    /* used for random */
    srand (time(NULL));

    vector<int> tour = nearestNeighbor(cities);
    int bestDistance = cities.tourDist(tour);

    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    while(currentTime < timeLimit){
        if (currentTime > timeLimit){ return tour; }

        for(int i = 0; i < tour.size()-1; i++){
            for (int j = 0; j < cities.getNNSize(); j++){
                currentTime = float(clock() - start)/CLOCKS_PER_SEC;
                if (currentTime > timeLimit){
                    return tour;
                }

                vector<int> newTour = swap(tour, i, cities.kNN[i][j]);

                int dist = cities.tourDist(newTour);

                if (dist < bestDistance) {
                    tour = newTour;
                    bestDistance = dist;
                    break;
                }
            }
        }
        currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    }
    return tour;
}





    /* From Wikipedia:
       1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
    */
vector<int> swap(vector<int>& tour, int i, int k )
{
    vector<int> newTour;

    for(int j = 0; j < i; ++j){
        newTour.push_back(tour[j]);
    }
    for(int l = k; l > i-1; --l){
        newTour.push_back(tour[l]);
    }
    for(int m = k+1; m < tour.size(); ++m){
        newTour.push_back(tour[m]);
    }

    return newTour;
}
