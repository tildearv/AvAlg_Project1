#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
#include <time.h> // timer
#include <vector>

using namespace std;

#include "Tabu2.h"

#define NO_ITERATIONS 100

Tabu2::Tabu2(){

}

vector<int> Tabu2::tabuSolve(Cities cities){

    size = cities.getNumCities();

    TABU_LENGTH = size;
    tabu_list = new int*[TABU_LENGTH];
    init = nearestNeighbor(cities);
    vector<int> currentSolution = init;
    int bestCost = cities.tourDist(init);
    bestSolution = init;

    if(size == 0){
        return init;
    }

    for(int i = 0; i < TABU_LENGTH; i++){      
        tabu_list[i] = new int[TABU_LENGTH];
    }
    if(size < 200){
        for(int i = 0; i < NO_ITERATIONS; ++i){
        //cout << "i1 = " << i <<endl;
            currentSolution = twoOpt(cities, currentSolution);
            currentCost = cities.tourDist(currentSolution);

            if(currentCost < bestCost){
                bestSolution = currentSolution;
                bestCost = currentCost;
            }
        }
    }
    return init;

}

void Tabu2::addTabuList(int city1, int city2){
    //cout <<"move "<<city1 <<"&"<<city2<<endl;
    tabu_list[city1][city2] += 5;
    tabu_list[city2][city1] += 5;
        
}

void Tabu2::resetTabuList(){
    for(int i = 0; i<TABU_LENGTH; ++i){
        for(int j = 0; j<TABU_LENGTH; ++j){
            //cout<<"decrementTabu"<<endl;
            tabu_list[i][j] -= tabu_list[i][j]<=0?0:1;
        } 
    }
}

vector<int> Tabu2::twoOpt(Cities cities, vector<int> currentSolution) {

    //int bestDistance = std::numeric_limits<int>::max();

    int bestDistance = cities.tourDist(currentSolution); 
    //cout << "bestDist = "<< bestDistance<<endl;
    bool first = true;
    int city1, city2 = 0;
    int i = 0;
        while (i < size-1){
           /// cout<<"i2 = " << i <<endl;
            for (int k = i + 1; k < size; k++){
                //cout << "k = " << k << endl;
                vector<int> newTour = swap(currentSolution, i, k);

                int dist = cities.tourDist(newTour);
                //cout<<TABU_LENGTH<<endl;
                if ((dist > bestDistance || first) && tabu_list[i][k] == 0) {
                    first = false;
                    city1 = i;
                    city2 = k;
                    currentSolution = newTour;
                    bestDistance = dist;
                }
            }
            ++i;
        }
    resetTabuList();
    addTabuList(city1, city2);
    return currentSolution;
}

vector<int> Tabu2::swap(vector<int>& tour, int i, int k ){
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
