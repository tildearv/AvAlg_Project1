#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "City.cpp"
#include <string>
#include <cstdlib>

using namespace std;

vector<City> buildNodes(istream& reader){
    //ifstream reader("./samples/tsp.in");
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
        //reader.close();
    return cities;
}

void nearestNeighbor(vector<City> cities){
    vector<int> tour;

    srand (time(NULL));
    int rnd = rand() % cities.size();
    City current = cities[rnd];
    tour.push_back(current.getVertexNum());
    cities.erase(cities.begin() + rnd);

    double best = 99999;
    int best_ind = -1;

    while(cities.size() > 0){
        for(int i=0; i<cities.size(); ++i){
            double dist = current.dist(cities[i]);
            if (dist < best){
                best = dist;
                best_ind = i;
            }
        }
        current = cities[best_ind];
        cities.erase(cities.begin() + best_ind);
        tour.push_back(current.getVertexNum());
        best = 99999;
    }


    for(int i=0; i!=tour.size(); i++){
        cout << tour[i] << endl;
    }
}





int main(int argc, char* argv[]) {
    istream* input = &cin; // input is stdin by default
    if(argc > 1) {
        input = new ifstream(argv[1]);
    }

    vector<City> cities = buildNodes(*input);
    nearestNeighbor(cities);

    return 0;
}
