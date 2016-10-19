#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <limits>
#include "twoOpt.h"

using namespace std;

vector<int> twoOpt(Cities cities) {

    vector<int> tour = nearestNeighbor(cities);
    int count = 0;
    int size = tour.size();
    /* cout << "size = " << cities.getNumCities()<< endl; */

    if(cities.getNumCities() == 0){
        return tour;
    }

    int bestDistance = cities.tourDist(tour);

    //cout << bestDistance << endl;
    if(size < 300){

        while (count < 3){
            int i = 1;
            while(i < size - 1){
                //cout << "i = " << i << endl;

                for (int k = i + 1; k < size; ++k){
                    //cout << "k = " << k << endl;
                    vector<int> newTour = swap(tour, i, k);

                    int dist = cities.tourDist(newTour);

                    /* cout << "newDist = " << dist << endl; */
                    if (dist < bestDistance) {
                        /* cout <<  bestDistance << endl; */
                        // Improvement found so reset
                        //cout << bestDistance << endl;
                        //cout << dist << endl;
                        count = 0;
                        tour = newTour;
                        bestDistance = dist;
                    }
                }
                ++i;
            }
            ++count;
        }

    }/*else{
        int mult = size%10;
        while (count < 3){
            int i = 1;
            while(i < size - 1){
                //cout << "i = " << i << endl;

                for (int k = i + 1; k < size; ++k){
                    //cout << "k = " << k << endl;
                    vector<int> newTour = swap(tour, i, k);

                    double dist = distance(newTour, cities);

                    //cout << "newDist = " << dist << endl;
                    if (dist < bestDistance) {
                        // Improvement found so reset
                        //cout << bestDistance << endl;
                        //cout << dist << endl;
                        count = 0;
                        tour = newTour;
                        bestDistance = dist;
                    }
                }
                i+=mult;
            }

        ++count;
        }
    }*/
    //cout << bestDistance << endl;
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
