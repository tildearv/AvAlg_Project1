#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
//#include <time.h> // timer
#include <vector>
#include <ctime>

#include "twoOpt.h"
using namespace std;


vector<int> opt2(Cities &cities, vector<int> tour){
    int size = tour.size();
    //cout<<"size = "<<size<<endl;
    for (int i = 0; i < size - 2; ++i){
        //cout<<"i = " << i<<endl;
        int a = tour[i];
        int b = tour[i+1];
        for (int k = i+2; k < size-1; ++k){
            //cout<<"k = " << k<<endl;
            /*if (k == i || k == i+1){
                continue;
            }*/

            int c = tour[k];
            int d = tour[k+1];

            //cout << i << i+1 << k << k+1 << endl; 

            if( (cities.ds(a, c) + cities.ds(b, d)) < (cities.ds(a, b) + cities.ds(c, d)) ){
                //cout<<"old tour dist; "<< cities.tourDist(tour)<<endl;
                //cout << a << b << c << d << endl;
                //cout<< "new"<<cities.ds(a, c) + cities.ds(b, d)<<endl;
                //cout<< "before"<<cities.ds(a, b) + cities.ds(c, d)<<endl;
                /*if (k < i){
                    vector<int> newTour = swap(tour, k, i);
                    //cout<<"after swap = "<<cities.tourDist(newTour)<<endl;
                    return newTour;
                }*/
                vector<int> newTour = swap(tour, i, k);
                //cout<<"after swap = "<<cities.tourDist(newTour)<<endl;
                return newTour;
            }
        }
    }
    //cout<<cities.tourDist(tour)<<endl;
    return tour;
}



vector<int> twoOpt(Cities &cities, double time) {

    clock_t start = clock();

    double currentTime = time;

    vector<int> tour = nearestNeighbor(cities);

    int bestDistance = cities.tourDist(tour);
    vector <int> bestTour = tour;

    double timeLimit = 1.95;
    clock_t end = clock();

    if(tour.size() == 0){
        return tour;
    }
    int iter = 0;

    while(currentTime < timeLimit){
        ++iter;
        vector<int> new_tour = opt2(cities, bestTour);
        int dist = cities.tourDist(new_tour);

        if (dist < bestDistance) {
            //cout<<"found better, "<<dist<<" - "<<bestDistance<<endl;
            bestTour = new_tour;
            bestDistance = dist;
        }
        end = clock();
        currentTime = double(end - start)/CLOCKS_PER_SEC;
    }
    //cout<<"iterations = "<<iter<<endl;
    //cout<<"time: "<<currentTime<<endl;
    return bestTour;
}

vector<int> swap(vector<int> tour, int i, int k ){
    /* From Wikipedia:
       1. take route[1] to route[i-1] and add in order to new_route
       2. take route[i] to route[k] and add in reverse to new_route
       3. take route[k+1] to end and add in order to new_route
    */
    //cout<<"i = "<<i<<endl;
    //cout<<"k = "<<k<<endl;
    /*for(int i=0; i<tour.size(); ++i){
        cout <<tour[i];
    }
    cout<<endl;*/
    reverse(tour.begin() + i+1, tour.begin() + k+1);
    //vector<int> newTour = tour;
   /* for(int i=0; i<tour.size(); ++i){
        cout <<tour[i];
    }
    cout<<endl;*/
    //cout<<tour[k]<<endl;
    //swap(tour[i+1], tour[k]);
    return tour;
}
