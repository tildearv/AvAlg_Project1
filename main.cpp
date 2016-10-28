#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>
#include <time.h> // timer


/* Algorithms */
#include "NearestNeighbor.h"
#include "Cities.h"
#include "twoOpt.h"
#include "Tabu2.h"

/* To run: ./a.out < "./samples/tsp.in" */
/* To compile: g++ NearestNeighbor.cpp City.cpp */

using namespace std;

int main(int argc, char* argv[]) {


    /* timer */
    clock_t start;
    start = clock();

    istream* input = &cin; // input is stdin by default
    if(argc > 1){
        input = new ifstream(argv[1]);
    }

    Cities cities(*input);
    //cities.findkNN();

    // use nearestNeighbor algorithm
    // comment out if you want another algorithm to run

    vector<int> tour = twoOpt(cities, start);
    /* vector<int> tour = nearestNeighbor(cities); */

    //Tabu2 tabu;
    //vector<int> tour = tabu.tabuSolve(cities);

    // outputs the tour to Kattis

    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }

    return 0;
}



