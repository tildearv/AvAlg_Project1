#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>

/* Header files */
#include "Cities.h"

using namespace std;



Cities::City::City(int vertex, float x, float y){
    this->vertex = vertex;
    this->x = x;
    this->y = y;
};


int Cities::City::dist(City i, City j){
    float xdist = i.getX() - j.getX();
    float ydist = i.getY() - j.getY();
    return  nearbyint(sqrt(xdist*xdist + ydist*ydist));
};



float Cities::City::getX(){ return City::x;};
float Cities::City::getY(){ return City::y;};
float Cities::City::getVertexNum(){ return City::vertex;};

Cities::Cities(istream& reader){
    string line;
    getline(reader, line); // first line is the num of cities
    this->numCities = stoi(line.c_str()); // str to int
    this->distances = vector< vector<int> > (numCities, vector<int>(numCities));

    for(int i = 0; i < this->numCities; i++){
        getline(reader, line); // x, y coordinates
        int index = line.find(" ", 0); // split on space

        // get x,y coordinates that are split on index
        float x = stod(line.substr(0,index).c_str());
        float y = stod(line.substr(index,line.length()).c_str());

        // create city and put it in cities array
        // cities are ordered by appearence
        this->listCities.push_back(Cities::City(i,x,y));
    }


    for(int i = 0; i < this->listCities.size(); i++){
        for (int j = i; j < this->listCities.size(); j++){
            int dij = Cities::City::dist(listCities[i], listCities[j]);
            /* symmetric distances */
            this->distances[i][j] = dij;
            this->distances[j][i] = dij;
        }
    }
};

int Cities::tourDist(vector<int> tour){
    int tourDist = 0;
    for (int i = 0; i < tour.size()-1; i++){
        tourDist += this->distances[tour[i]][tour[i+1]];
    }
    tourDist += this->distances[tour[tour.size()-1]][tour[0]];
    return tourDist;
};

/* calculate distance between city i and city j */
int Cities::distance(int i, int j){
    return  this->distances[i][j];
};

int Cities::getNumCities(){return this->numCities;};

