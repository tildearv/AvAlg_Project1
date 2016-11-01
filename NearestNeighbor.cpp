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
    //srand (time(NULL));
    int thisvertex = 0;//rand() % cities.getNumCities();
    //cout<<thisvertex<<endl;

    // put in the first city and delete it from cities
   // tour.push_back(thisvertex);


    // some variables to keep track of best
    double best = numeric_limits<double>::max();
    //int best_ind = -1;

    bool used[N];

    for(int i = 0; i < N; ++i){
        used[i] = false;
        tour.push_back(0);
    }
    used[0] = true;
    for(int i = 1; i < N; ++i){
        int best_ind = -1;
        best = numeric_limits<double>::max();
        //int best = numeric_limits<int>::max();
        for(int j=0; j < N; ++j){
            // calc distance between thisvertex and j
            if(used[j] ==false){
            //if( ( find(tour.begin(), tour.end(), j) == tour.end() )){
                int thisdist = cities.ds(tour[i-1], j);
                if (thisdist < best || best_ind == -1){
                    best = thisdist;
                    best_ind = j;
                }
            }
        }
        //if(best_ind == -1){best_ind = 0;}
        tour[i] = best_ind;
        used[best_ind] = true;
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout<<"time after NN = "<<elapsed_secs<<endl;
    return tour;
}

/*vector<int> nearestNeighbor(Cities &cities){

    clock_t begin = clock();

    vector<int> tour;
    int N = cities.getNumCities();

    // take some random vertex
    srand (time(NULL));
    int thisvertex = 0;//rand() % cities.getNumCities();
    //cout<<thisvertex<<endl;

    // put in the first city and delete it from cities
    tour.push_back(thisvertex);


    // some variables to keep track of best
    double best = numeric_limits<double>::max();
    //int best_ind = -1;

    while( tour.size() < N ){
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
        //cout<<best_ind<<endl;
        //if(best_ind == -1){best_ind = 0;}
        thisvertex = best_ind;
        tour.push_back(thisvertex);
        best = numeric_limits<double>::max();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"time after NN = "<<elapsed_secs<<endl;
    return tour;
}*/


