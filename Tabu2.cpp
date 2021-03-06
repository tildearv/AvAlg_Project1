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
#define TABU_ITER 5

//Tabu2::Tabu2(){

//}

vector<int> Tabu2::tabuSolve(Cities cities, clock_t start){

    float timeLimit = 2*0.9;
    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;

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
    resetTabuList();

    while(currentTime < timeLimit){
        float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
        if (currentTime > timeLimit){ return currentSolution; }
        for(int i = 0; i < NO_ITERATIONS; ++i || timeLimit > currentTime){
            float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
            if (currentTime > timeLimit){ return currentSolution; }
        //cout << "i1 = " << i <<endl;
            currentSolution = twoOpt(cities, currentSolution, timeLimit);
            currentCost = cities.tourDist(currentSolution);

            if(currentCost < bestCost){
                bestSolution = currentSolution;
                bestCost = currentCost;
            }
        }
    }
    return bestSolution;

}

void Tabu2::addTabuList(int city1, int city2){
    //cout <<"move "<<city1 <<"&"<<city2<<endl;
    tabu_list[city1][city2] += TABU_ITER;
    tabu_list[city2][city1] += TABU_ITER;
        
}

void Tabu2::resetTabuList(){
    for(int i = 0; i<TABU_LENGTH; ++i){
        for(int j = 0; j<TABU_LENGTH; ++j){
            //cout<<"decrementTabu"<<endl;
            tabu_list[i][j] -= tabu_list[i][j]<=0?0:1;
        } 
    }
}

vector<int> Tabu2::twoOpt(Cities cities, vector<int> currentSolution, float timeLimit) {

    //int bestDistance = std::numeric_limits<int>::max();

    int bestDistance = cities.tourDist(currentSolution); 
    //cout << "bestDist = "<< bestDistance<<endl;
    bool first = true;
    int city1, city2 = 0;
    int i = 0;
    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    if (currentTime > timeLimit){ return currentSolution; }
        while (i < size-1){
            float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
            if (currentTime > timeLimit){ return currentSolution; }
           /// cout<<"i2 = " << i <<endl;
            for (int k = i + 1; k < size; k++){
                float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
                if (currentTime > timeLimit){ return currentSolution; }
                //cout << "k = " << k << endl;
                vector<int> newTour = currentSolution;
                swap(newTour[i], newTour[k]);
                int dist = cities.tourDist(newTour);
                //cout<<TABU_LENGTH<<endl;
                if ((dist > bestDistance || first) && tabu_list[i][k] == 0) {
                    float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
                    if (currentTime > timeLimit){ return currentSolution; }
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

/*vector<int> Tabu2::swap(vector<int>& tour, int i, int k ){
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
}*/
