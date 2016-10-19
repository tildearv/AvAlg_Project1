#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>


/* Algorithms */
#include "NearestNeighbor.h"
#include "Cities.h"
/* #include "twoOpt.h" */



/* To run: ./a.out < "./samples/tsp.in" */
/* To compile: g++ NearestNeighbor.cpp City.cpp */

using namespace std;

int main(int argc, char* argv[]) {
    istream* input = &cin; // input is stdin by default
    if(argc > 1){
        input = new ifstream(argv[1]);
    }

    Cities cities(*input);

    // use nearestNeighbor algorithm
    // comment out if you want another algorithm to run

    /* vector<int> tour = twoOpt(cities); */
    vector<int> tour = nearestNeighbor(cities);



    // outputs the tour to Kattis
    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }

    return 0;
}



