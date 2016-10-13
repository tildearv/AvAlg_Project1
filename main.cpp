#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>


/* Algorithms */
//#include "NearestNeighbor.h"
#include "twoOpt.h"


/* To run: ./a.out < "./samples/tsp.in" */
/* To compile: g++ NearestNeighbor.cpp City.cpp */

using namespace std;

vector<City> buildNodes(istream& reader){
    vector<City> cities; // store all cities

    string line;
    getline(reader, line); // first line is the num of cities
    int numCities = stoi(line.c_str()); // str to int

    for(int i = 0; i < numCities; i++){
        getline(reader, line); // x, y coordinates
        int index = line.find(" ", 0); // split on space

        // get x,y coordinates that are split on index
        float x = stod(line.substr(0,index).c_str());
        float y = stod(line.substr(index,line.length()).c_str());

        // create city and put it in cities array
        // cities are ordered by appearence
        City city(i,x,y);
        cities.push_back(city);
    }
    return cities;
}



int main(int argc, char* argv[]) {
    istream* input = &cin; // input is stdin by default
    if(argc > 1){
        input = new ifstream(argv[1]);
    }

    vector<City> cities = buildNodes(*input);

    // use nearestNeighbor algorithm
    // comment out if you want another algorithm to run

    vector<int> tour = twoOpt(cities); 
    //vector<int> tour = nearestNeighbor(cities);



    // outputs the tour to Kattis
    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }

    return 0;
}
