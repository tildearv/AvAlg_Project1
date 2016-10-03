#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>
#include "City.h"


#include "NN.h"

//To run: ./NN.o < "./samples/tsp.in"

using namespace std;

vector<City> buildNodes(istream& reader){
        string line;
        getline(reader, line);
        int numCities = std::stoi(line.c_str());
        vector<City> cities;
        for(int i = 0; i < numCities; i++){
            getline(reader, line);
            int index = line.find(" ", 0);
            float x = std::stod(line.substr(0,index).c_str());
            float y = std::stod(line.substr(index,line.length()).c_str());
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

    vector<int> tour = nearestNeighbor(cities);

    for(int i=0; i<tour.size(); ++i){
        cout << tour[i] << endl;
    }

    return 0;
}
