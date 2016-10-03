#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include "types.h"

using namespace std;


vector<int> swap(vector<int>& tour, int& i, int& k ) 
{
    return tour;
}

void twoOpt(vector<int> tour) {

    int improve = 0;

    int size = tour.size();
 
    while ( improve < 20 )
    {
        for ( int i = 0; i < size - 1; i++ ) 
        {
            for ( int k = i + 1; k < size; k++) 
            {
                swap(tour, i, k);
 
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

// From wikipedia psuedocode:
// http://en.wikipedia.org/wiki/2-opt

// 1. take route[0] to route[i-1] and add them in order to new_route
// 2. take route[i] to route[k] and add them in reverse order to new_route
// 3. take route[k+1] to end and add them in order to new_route

void swap(vector<int> tour, int i, int k ) 
{
    //return tour;
}

