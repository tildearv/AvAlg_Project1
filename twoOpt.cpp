#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <tuple>
#include <stdlib.h> // srand
//#include <time.h> // timer
#include <vector>
#include <ctime>

#include "TwoOpt.h"
using namespace std;

TwoOpt::TwoOpt(){

};

tuple<int, vector<int>> TwoOpt::opt2(Cities &cities, vector<int> tour){
    int size = tour.size();
    //cout<<"size = "<<size<<endl;
    for (int i = it; i < size - 3; ++i){
        int a = tour[i];
        int b = tour[i+1];
        for (int k = i+2; k < size-1; ++k){
            //cout<<"k = " << k<<endl;

            int c = tour[k];
            int d = tour[k+1];

            int old_dist = cities.ds(a, b) + cities.ds(c, d);
            int new_dist = cities.ds(a, c) + cities.ds(b, d);

            if( new_dist < old_dist ){
                //cout << i << " " << k <<endl;
                //cout<<"old tour dist; "<< cities.tourDist(tour)<<endl;
                //cout << a << b << c << d << endl;
                //cout<< "new"<<cities.ds(a, c) + cities.ds(b, d)<<endl;
                //cout<< "before"<<cities.ds(a, b) + cities.ds(c, d)<<endl;
                it = i;
                vector<int> newTour = swap(tour, i, k);
                //cout<<"after swap = "<<cities.tourDist(newTour)<<endl;
                return make_tuple((old_dist - new_dist), newTour);
            }
        }
    }
    //cout<<cities.tourDist(tour)<<endl;
    it = 0;
    return make_tuple(0, tour);
};



vector<int> TwoOpt::twoOpt(Cities &cities, double time) {

    clock_t start = clock();
    it = 0;
    double currentTime = time;

    vector<int> tour = nearestNeighbor(cities);

    int bestDistance = cities.tourDist(tour);
    vector <int> bestTour = tour;

    double timeLimit = 1.95;
    clock_t end = clock();

    if(tour.size() == 0){
        return tour;
    }
    //int iter = 0;

    while(currentTime < timeLimit){
        //++iter;
        auto new_tour_tuple = opt2(cities, bestTour);
        if (get<0>(new_tour_tuple) != 0) {
            //cout<<"it = "<<it<<endl;
            vector<int> new_tour = get<1>(new_tour_tuple);
            //int dist = best;
            bestTour = new_tour;
            bestDistance -= get<0>(new_tour_tuple);
        }
        end = clock();
        currentTime = double(end - start)/CLOCKS_PER_SEC;
    }
    //cout<<"iterations = "<<iter<<endl;
    //cout<<"time: "<<currentTime<<endl;
    return bestTour;
};

vector<int> TwoOpt::swap(vector<int> tour, int i, int k ){
    /* From Wikipedia:
       1. take route[1] to route[i-1] and add in order to new_route
       2. take route[i] to route[k] and add in reverse to new_route
       3. take route[k+1] to end and add in order to new_route
    */

    reverse(tour.begin() + i+1, tour.begin() + k+1);
    return tour;
};
