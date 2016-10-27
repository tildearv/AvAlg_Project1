#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
#include <time.h> // timer
#include <vector>

#include "twoOpt.h"
using namespace std;

vector<int> twoOpt(Cities cities, clock_t start) {

    /* used for random */
    srand (time(NULL));

    vector<int> tour = nearestNeighbor(cities);

    if(cities.getNumCities() == 0){
        return tour;
    }

    int bestDistance = cities.tourDist(tour);
    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    int size = tour.size();

    while( currentTime < 1.9){
            if (currentTime > 1.9){
                return tour;
            }
            int i = 0;
            while (i < size-1){
                for (int k = i + 1; k < size; k++){
                    currentTime = float(clock() - start)/CLOCKS_PER_SEC;
                    if (currentTime > 1.9){
                        return tour;
                    }
                    vector<int> newTour = swap(tour, i, k);
                    int dist = cities.tourDist(newTour);

                    if (dist < bestDistance) {
                        tour = newTour;
                        bestDistance = dist;
                    }
                }
                i++;
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
