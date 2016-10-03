#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>


using namespace std;

vector<int> nearestNeighbor(vector<City> cities){

    vector<int> tour;

    srand (time(NULL));
    int rnd = rand() % cities.size();
    City current = cities[rnd];
    tour.push_back(current.getVertexNum());
    cities.erase(cities.begin() + rnd);

    float best = numeric_limits<float>::max();
    int best_ind = -1;

    while(cities.size() > 0){
        for(int i=0; i!=cities.size(); ++i){
            float dist = current.dist(cities[i]);
            if (dist < best){
                best = dist;
                best_ind = i;
            }
        }
        current = cities[best_ind];
        cities.erase(cities.begin() + best_ind);
        tour.push_back(current.getVertexNum());
        best = numeric_limits<float>::max();
    }
    return tour;
}
