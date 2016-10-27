#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdlib.h> // srand
#include <time.h> // timer
#include <vector>

#include "TabuSearch.h"

using namespace std;
#define TABU_LENGTH 30
#define MAX_ITERATION 100
#define PENAL_LONG_TERM 10
#define LONG_TERM_LENGTH 100
#define TIME_TRY 500

/*  
    http://www.eng.uwaterloo.ca/~sjayaswa/projects/MSCI703_project.pdf

     The simplest way to generate such a tabo list is by keeping track of recent searches and including them into the tabu list in 
     order for the algorithm to 'explore' different possiblilities. An example for tabu list heuristic is: if from city D you've 
     went to city E less than 'n' iterations ago where 'n' is the number of previous solutions to be stored it's added into the tabu list 
     ( elements in the tabu list have expiration )


    It choses an initial state ( may be at random ) and set it as the best option.

    It enters in a loop checking if a condiotion to break given by the user is met ( can be threshold or traveling cost for this example ).

    It creates an empty candidate list. Each of the candidates in a given neigbour which does not contain a tabu element are added to this empty candidate list.

    It finds the best candidate on this list and if it's cost is better than the current best it's marked as a solution.

    If the number of tabus on the tabu list have reached the maximum number of tabus ( you are defining the number ) a tabu expires. The tabus on the list expires in the order they have been entered .. first in first out.
*/

TabuSearch::TabuSearch(Cities cities, clock_t start){
    bestSolverScore = numeric_limits<float>::max();
    init = nearestNeighbor(cities);
    size = init.size();

    tabu_list = new int*[size];
    tabu_f_list = new int*[size];

    for(int i = 0; i < size; i++){
        tabu_f_list[i] = new int[size];       
        tabu_list[i] = new int[size];
    }
    resetTabuList();
}

void TabuSearch::resetTabuList(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            tabu_list[i][j] = 0;
            tabu_f_list[i][j] = 0;
        }
    }
}

vector<int> TabuSearch::solve(Cities cities, clock_t start, int iter){

    if(cities.getNumCities() == 0){
        return init;
    }

    if (size < 50){

    int bestSolutionScore = cities.tourDist(init);

    for(int i = 0; i < iter; ++i){
        solution = init;
        resetTabuList();

        int count = 0;

        bestSolverScore = numeric_limits<float>::max();;

        for(int j = 0; j < MAX_ITERATION; ++j){
            solution = twoOpt(cities, j);
            int score = cities.tourDist(solution);
            if(score < bestSolverScore){
                bestSolverScore = score;
                count = 0;

                if(bestSolverScore < bestSolutionScore){
                    for(int k = 0; k < size; ++k){
                        bestSolution = solution;
                    }   
                    bestSolutionScore = bestSolverScore;
                }                               
            }else{
                ++count;
                if(count > TIME_TRY){                   
                    break;  
                } 
            }
        }
        return bestSolution;
    }
    }
    else{return init;}
}

vector<int> TabuSearch::twoOpt(Cities cities, int iter) {

    /* used for random */
    srand (time(NULL));

    int bestDistance = cities.tourDist(solution);

    int i = 0;
        while (i < size-1){
            for (int k = i + 1; k < size; k++){
                vector<int> newTour = swap(solution, i, k);
                int dist = cities.tourDist(newTour);
                int penalDist = dist + PENAL_LONG_TERM + tabu_list[i][k];

                if (dist < bestDistance && tabu_list[i][k] <= iter || dist < bestSolverScore) {
                    solution = newTour;
                    bestDistance = dist;
                }
            }
            ++i;
        }

    return solution;
}

vector<int> TabuSearch::swap(vector<int>& tour, int i, int k ){
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

/*void tabu(Cities cities, clock_t start){

    SA criteria:

    1. Max number of iterations reached
    2. Acceptance Ratio is less than the threshold 
    3. No improvement in last fixed number of iterations 
    

    int maxIter = 1000;
    int transTemp = 100;
    int acceptedTemp = 50;


    vector<int> init_state = nearestNeighbor(cities);
    vector<int> currentState = init_state;

    double T = Cities::tourDist(init_state);

    doule alpha = 0.99;
    doule rf = 0.1;

    int iter = 0;
    iterLastChange = 0;
    int accRatio = 1;

    while (iter < maxIter && accRatio > rf){
        double currentTemp = Cities::tourDist(currentState);
        ++iter;
        int transTried = 0;
        int transAccept = 0;

        while(transTried < transTemp && transAccept < acceptedTemp){

            ++transTried;
            int i, j;
            int city1 = int thisvertex = rand() % cities.getNumCities();
            int city2 = int thisvertex = rand() % cities.getNumCities();
            vector<int> neighbor;

            while(city1==city2){
                city2 = int thisvertex = rand() % cities.getNumCities();
            }

            if(city2 > city1){
                i = city1;
                j = city2;
            }else{
                i = city2;
                j = city1;
            }
            neighbor(i) = currentState(j);
            neighbor(j) = currentState(i);

            if(j-i = 1){
                int tempCost = currentTemp - 
            }

            double delta = nbr_cost - crnt_tour_cost; 
            double prob1 = exp(-delta/T); 
            double prob2 = random('uniform',0,1); 

            if(delta < 0 || prob2 < prob1){
                sum = sum+delta;
                currentState = neighbor;
                currentTemp = tempCost;
                ++transAccept;
                if(currentTemp < bestObj){
                    bestObj = currentTemp;
                    bestTour = currentState;
                }
            }
            else{
                neighbor = currentState;
                tempCost = currentTemp;
            }

        }

    }
}*/