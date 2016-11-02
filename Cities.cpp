#include <algorithm>
#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>
#include <time.h>

/* Header files */
#include "Cities.h"

using namespace std;

Cities::Ncity::Ncity(int vertex, int dist) {
    this->dist = dist;
    this->vertex = vertex;
};

bool Cities::Ncity::operator<(const Ncity &nc2) const {
    return this->dist < nc2.dist;
}

Cities::City::City(int vertex, float x, float y){
    this->vertex = vertex;
    this-> x = x;
    this-> y = y;
};

float Cities::City::getX(){ return City::x;};
float Cities::City::getY(){ return City::y;};
float Cities::City::getVertexNum(){ return City::vertex;};



int Cities::getNumCities(){return this->numCities;};
int Cities::dist(City i, City j){
    float xdist = i.getX() - j.getX();
    float ydist = i.getY() - j.getY();
    return  nearbyint(sqrt(xdist*xdist + ydist*ydist));
};

bool comp(const Cities::City &c0, const Cities::City &c1,\
        const Cities::City &c2){
    return Cities::dist(c0, c1) < Cities::dist(c0, c2);
}

Cities::Cities(istream& reader){
    /* clock_t start; */
    /* start = clock(); */

    string line;
    getline(reader, line); // first line is the num of cities

    this->numCities = stoi(line); // str to int

    this->distances = vector< vector<int> > (this->numCities,\
            vector<int>(this->numCities));

    if (this->numCities > 20) {
        this->maxNN = 20;
    } else {
        this->maxNN = this->numCities-1;
    }


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

    /* cout << float(clock() - start)/CLOCKS_PER_SEC << endl; */

    for(int i = 0; i < this->numCities; i++){
        for(int j = i; j < this->numCities; j++){
            City a = this->listCities[i];
            City b = this->listCities[j];
            int dij = Cities::dist(a,b);
            /* cout << dij << endl; */
            /* symmetric distances */
            this->distances[i][j] = dij;
            this->distances[j][i] = dij;
        }
    }
};

int Cities::tourDist(vector<int> &tour){
    int tourDist = 0;
    for (int i = 0; i < tour.size()-1; ++i){
        tourDist += this->distances[tour[i]][tour[i+1]];
    }
    tourDist += this->distances[tour[tour.size()-1]][tour[0]];
    return tourDist;
};


/* return distance between city i and city j */
int Cities::ds(int i, int j){
    return this->distances[i][j];
};


void Cities::findkNN(){
    /*  This solution assumes cities is ordered so that cities[k] has */
    /* vertexnum k.                                                   */


    /* loop through every city */
    for (int i = 0; i < this->numCities; i++){

        /* Parameters for  finding the  city with largest  distance. */
        int largest = -1;
        int swap = -1; // swap index of the city with largest dist

        int neighbor = 0;
        vector<Ncity> tempList;

        /* for every city, save the kth neighbor */
        for (int j = 0; j < this->numCities; j++){

            /* skip if we look at the same city */
            if (j == i){
                continue;
            } else {

                int thisdist = this->distances[i][j];
                City b = this->listCities[j];

                /* if we have not found maxNeighbors, just put in cities */

                if(neighbor < this->maxNN){
                    Ncity nb = Cities::Ncity(b.getVertexNum(), thisdist);
                    tempList.push_back(nb);

                    /* keep track of the city with biggest distance */
                    if (thisdist > largest ){

                        auto max = max_element(begin(tempList), end(tempList));

                        swap = distance(begin(tempList), max);
                        largest = max->dist;
                    }

                    neighbor++;

                }else if (thisdist < largest){
                    /* maxNeighbors numbers of neighbors to city i */
                    /* swap is indx of city with biggest distance */
                    Ncity nb = Cities::Ncity(b.getVertexNum(), thisdist);

                    /* swap since city j is closer to city i */
                    tempList[swap] = nb;

                    /* find city with largest dist to city i */
                    auto max = max_element(begin(tempList), end(tempList));
                    swap = distance(begin(tempList), max);
                    largest = max->dist;
                }
            }
        }

        sort(tempList.begin(), tempList.end());
        this->kNN.push_back(tempList);

        /* cout << "--------" << endl; */
        /* for (int m = 0; m < this->maxNN; m++){ */
        /*     cout << tempList[m].vertex << endl; */
        /* } */
        /* cout << "--------" << endl; */


    }
};
