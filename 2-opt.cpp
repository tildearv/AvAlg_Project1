#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include "types.h"

using namespace std;

    /*
       1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
    */

vector<int> swap(vector<int>& tour, int& i, int& k ) 
{
    vector<int> newTour;

    for(int j = 0; j < i; ++j){
        newTour.push_back(tour[j]);
    }
    for(int l = k; l > i-1; --l){
        newTour.push_back(tour[l]);
    }
    for(int m = k+1; k < tour.size(); ++k){
        newTour.push_back(tour[m]);
    }

    return tour;
}

void twoOpt(vector<int> tour) {

    int improve = 0;

    int size = tour.size();
 
    while ( improve < 20 )
    {
        for (int i = 0; i < size - 1; ++i) 
        {
            for (int k = i + 1; k < size; ++k) 
            {
                vector<int> newTour = swap(tour, i, k);
 
                /*if ( new_distance < best_distance ) 
                {
                    // Improvement found so reset
                    improve = 0;
                    tour = new_tour;
                    best_distance = new_distance;
                    Notify( tour.TourDistance() );
                }*/
            }
        }
 
        improve ++;
    }
}
