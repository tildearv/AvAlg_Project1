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

    //clock_t begin = clock();

    vector<int> tour;
    int N = cities.getNumCities();

    // take some random vertex
    //srand (time(NULL));
    int thisvertex = 0;//rand() % cities.getNumCities();
    //cout<<thisvertex<<endl;

    // put in the first city and delete it from cities
    tour.push_back(thisvertex);

    /*   tour[0] = 0
   used[0] = true
   for i = 1 to n-1
      best = -1
      for j = 0 to n-1
         if not used[j] and (best = -1 or dist(tour[i-1],j) < dist(tour[i-1],best))
            best = j
      tour[i] = best
      used[best] = true
   return tour */


    // some variables to keep track of best
    int best = numeric_limits<int>::max();
    //int best_ind = -1;

    int i = 1;

    while( i < N ){
        int best_ind = -1;
        for(int j=0; j < N; ++j){
            // calc distance between thisvertex and j
            if( ( find(tour.begin(), tour.end(), j) == tour.end() )){
                int thisdist = cities.ds(thisvertex, j);
                if (thisdist < best){
                    best = thisdist;
                    best_ind = j;
                }
            }
        }
        ++i;
        //cout<<best_ind<<endl;
        //if(best_ind == -1){best_ind = 0;}
        thisvertex = best_ind;
        tour.push_back(thisvertex);
        best = numeric_limits<int>::max();
    }
    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout<<"time after NN = "<<elapsed_secs<<endl;
    return tour;
}
