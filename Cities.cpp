#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>
#include <time.h>

/* Header files */
#include "Cities.h"

using namespace std;


Cities::City::City(int vertex, float x, float y){
    this->vertex = vertex;
    this-> x = x;
    this-> y = y;
};

int Cities::dist(City i, City j){
    float xdist = i.getX() - j.getX();
    float ydist = i.getY() - j.getY();
    return  nearbyint(sqrt(xdist*xdist + ydist*ydist));
};

float Cities::City::getX(){ return City::x;};
float Cities::City::getY(){ return City::y;};
float Cities::City::getVertexNum(){ return City::vertex;};






Cities::Cities(istream& reader){
    /* clock_t start; */
    /* start = clock(); */

    string line;
    getline(reader, line); // first line is the num of cities

    this->numCities = stoi(line); // str to int
    this->distances = vector< vector<int> > (this->numCities, vector<int>(this->numCities));

    /*if (this->numCities > 20){
        this->kNN = vector< vector<int> >\
                    (this->numCities, vector<int>(20));
    } else {
        this->kNN = vector< vector<int> >\
                    (this->numCities, vector<int>(this->numCities));
    }

    */
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
    for (int i = 0; i < tour.size()-1; i++){
        tourDist += this->distances[tour[i]][tour[i+1]];
    }
    tourDist += this->distances[tour[tour.size()-1]][tour[0]];
    return tourDist;
};





/* return distance between city i and city j */
int Cities::ds(int i, int j){
    //cout<<" i = "<<i<<"j = "<<j<<endl;
    //cout<<"distance "<<distances[i][j]<<endl;
    return this->distances[i][j];
};






int Cities::getNumCities(){return this->numCities;};

int Cities::getNNSize(){return this->kNN[0].size();};



void Cities::findkNN(){
    /*  This solution assumes cities is ordered so that cities[k] has */
    /* vertexnum k.                                                   */

    int maxNeighbors = this->kNN[0].size();

    /* Parameters for  finding the  city with largest  distance. */
    int largest = -1;
    int swap = -1; // swap index of the city with largest dist

    /* loop through every city */
    for (int i = 0; i < this->numCities; i++){
        int neighbors = 0;

        /* for every city, save the mth neighbor */
        for (int j = 0; j < this->numCities; j++){

            /* skip if we look at the same city */
            if ( j == i){
                continue;
            }

            int thisdist = this->distances[i][j];

            /* if we have not found nnMax neighbors, just put cities */
            if( neighbors < maxNeighbors){
                this->kNN[i][neighbors] = j;

                /* keep track of the city with biggest distance */
                if (thisdist > largest ){
                    largest = thisdist;
                    swap = neighbors;
                }

                neighbors++;

            }else if (thisdist > largest){
                /* maxNeighbors numbers of neighbors to city i */
                /* swap is indx of city with biggest distance */

                /* swap since city j is closer to city i */
                this->kNN[i][swap] = j;
                largest = -1;

                /* find city with largest dist to city i */
                for (int k = 0; k < maxNeighbors; k++){
                    int thisdist = this->distances[i][k];
                    if (thisdist > largest){
                        largest = thisdist;
                        swap = k;
                    }
                }
            }
        }
    }
};
