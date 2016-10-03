#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

    /*
       1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
    */

vector<int> swap(vector<int>& tour, int& i, int& k ) 
{
    vector<int> newTour;

    for(int j = 0; j < i-1; ++j){
        newTour.push_back(tour[j]);
    }
    for(int l = k; l > i; --l){
        newTour.push_back(tour[l]);
    }
    for(int m = k; k < tour.size(); ++k){
        newTour.push_back(tour[m]);
    }

    return tour;
}

vector<int> twoOpt(vector<int> tour, vector<City> cities) {

    int improve = 0;
    int size = tour.size();

    //Need to make distance-funtion!

    float bestDistance = 0.0;

    for (int j = 0; j < tour.size()-1; ++j){

        bestDistance += cities[tour[j]].dist(cities[tour[j+1]]);

    }
 
    while (improve < 2)
    {
        for (int i = 0; i < size - 1; ++i) 
        {
            for (int k = i + 1; k < size; ++k) 
            {
                vector<int> newTour = swap(tour, i, k);

                float dist = 0.0;

                for (int j = 0; j < newTour.size()-1; ++j){

                    dist += cities[newTour[j]].dist(cities[newTour[j+1]]);

                }
 
                if (dist < bestDistance) 
                {
                    // Improvement found so reset
                    improve = 0;
                    tour = newTour;
                    bestDistance = dist;
                    //Notify(tour.TourDistance() );
                }
            }
        }
 
        improve ++;
    }

    return tour;
}
