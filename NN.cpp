#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "City.cpp"

using namespace std;

vector<City> buildNodes(){
    ifstream reader("./samples/tsp.in");
        string line;
        getline(reader, line);
        int numCities = stoi(line);
        vector<City> cities;
        for(int i = 0; i < numCities; i++){
            getline(reader, line);
            int index = line.find(" ", 0);
            float x = stod(line.substr(0,index));
            float y = stod(line.substr(index,line.length()));
            City city(i,x,y);
            cities.push_back(city);
        }
        reader.close();
    return cities;
}

void nearestNeighbor(vector<City> cities){
    vector<int> tour;

    srand (time(NULL));
    int rnd = rand() % cities.size();
    City current = cities[rnd];
    tour.push_back(current.getVertexNum());
    cities.erase(cities.begin() + rnd);

    float best = 99999;
    int best_ind = -1;

    while(cities.size() > 0){
        for(int i=0; i!=cities.size(); i++){
            float dist = current.dist(cities[i]);
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





int main() {
    vector<City> cities = buildNodes();
    nearestNeighbor(cities);
    return 0;
}
