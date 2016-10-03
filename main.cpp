#include <fstream> // istream I/O
#include <iostream> // cout
#include <vector>

/* Help classes */
#include "City.h"


/* Algorithms */
#include "NN.h"


//To run: ./NN.o < "./samples/tsp.in"

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

    if(cities.size() == 0){
        return 0;
    }

    if(cities.size() == 1){
        cout << 0 << endl;
        return 0;
    }

    // use nearestNeighbor algorithm
    // uncomment if you want another algorithm to run
    vector<int> tour = nearestNeighbor(cities);

    // outputs the tour
    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }

    return 0;
}
