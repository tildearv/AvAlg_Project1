#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>
#include <algorithm>
//#include <time.h> // timer
#include <ctime>

/* Algorithms */
#include "NearestNeighbor.h"
#include "Cities.h"
#include "TwoOpt.h"
/* #include "Tabu2.h" */

/* To run: ./a.out < "./samples/tsp.in" */
/* To compile: g++ NearestNeighbor.cpp City.cpp */

using namespace std;

int main(int argc, char* argv[]) {


    /* timer */
    clock_t start = clock();

    istream* input = &cin; // input is stdin by default
    if(argc > 1){
        input = new ifstream(argv[1]);
    }

    Cities cities(*input);
    Cities &rcities = cities;
    clock_t end = clock();

    double currentTime = double(end - start) / CLOCKS_PER_SEC;

    //float currentTime = float(clock() - start)/CLOCKS_PER_SEC;
    //cout<<"Time after init: "<<currentTime<<endl;
    /* cities.findkNN(); */

    // use nearestNeighbor algorithm
    // comment out if you want another algorithm to run

    TwoOpt twoopt;

    vector<int> tour = twoopt.twoOpt(rcities, currentTime);
    //vector<int> tour = nearestNeighbor(cities); 


     /* outputs the tour to Kattis */
    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }
    //cout<<"distance = " << cities.tourDist(tour)<<endl;

    return 0;
}
