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
    /* clock_t start; */
    /* start = clock(); */

    string line;
    getline(reader, line); // first line is the num of cities
    this->numCities = stoi(line.c_str()); // str to int
    this->distances = vector< vector<int> > (numCities, vector<int>(numCities));
    this->kNN = vector< vector<int> > (numCities, vector<int>(9));
    vector< vector<float> > xycords = vector< vector<float> >(this->numCities, vector<float>(this->numCities));

    for(int i = 0; i < this->numCities; i++){
        getline(reader, line); // x, y coordinates
        int index = line.find(" ", 0); // split on space

        // get x,y coordinates that are split on index
        float x = stod(line.substr(0,index).c_str());
        float y = stod(line.substr(index,line.length()).c_str());

        // create city and put it in cities array
        // cities are ordered by appearence
        /* this->listCities.push_back(Cities::City(i,x,y)); */
        xycords[i][0] = x;
        xycords[i][1] = y;
    }
    /* cout << float(clock() - start)/CLOCKS_PER_SEC << endl; */

    for(int i = 0; i < this->numCities; i++){
        for (int j = i; j < this->numCities; j++){
            float xdist = xycords[i][0] - xycords[j][0];
            float ydist = xycords[i][1] - xycords[j][1];
            int dij = nearbyint(sqrt(xdist*xdist + ydist*ydist));
            /* cout << dij << endl; */
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



void Cities::findkNN(){

    /*  This solution assumes cities is ordered so that cities[k] has */
    /* vertexnum k.                                                   */

    /* Parameters for  finding the  city with largest  distance. */
    int largest = -1;
    int swap = -1; // swap index of the city with largest dist

    /* loop through every city */
    for (int i = 0; i < this->numCities; i++){
        int m = 0;

        /* for every city, save the mth neighbor */
        for (int j = 0; j < this->numCities; j++){

            /* skip if we look at the same city */
            if ( j == i){
                continue;
            }

            int thisdist = this->distances[i][j];

            /* if we have not found nnMax neighbors, just put cities */
            if( m < 9){
                this->kNN[i][m] = j;
                /* keep track of the city with biggest distance */
                if (thisdist > largest ){
                    largest = thisdist;
                    swap = m;
                }
                m++;
            }else if (thisdist > largest){
                /* nnMax numbers of neighbors to city i */
                /* swap is indx of city with biggest distance */

                /* swap since city j is closer to city i */
                cout << "i" << i << "j" << j << "swap" << swap << endl;
                this->kNN[i][swap] = j;
                largest = -1;

                /* find city with largest dist to city i */
                for (int k = 0; k < 9; k++){
                    int thisdist= this->distances[i][k];
                    if (thisdist > largest){
                        largest = thisdist;
                        swap = k;
                    }
                }
            }
        }
    }
    cout << "nearest neighbors for 0" << endl;
    for (int w=0; w < 9; w++){
        cout << this->kNN[0][w] << endl;
    }
    cout << "end of nearest neigbors" << endl;
    sortkNN();
    cout << "nearest neighbors for 0 after sort" << endl;
    for (int w=0; w < 9; w++){
        cout << this->kNN[0][w] << endl;
    }
    cout << "end of nearest neigbors after sort" << endl;
};


void Cities::sortkNN(){
    for (int k = 0; k < this->numCities; k++){
        for (int i = 1; i < 9; i++){
            int j = i;
            if (k == 0){
                cout << "j is " << j<< endl;
            }
            while( j > 0 and this->distances[k][j-1] > this->distances[k][j]){
                if (k == 0){
                    cout << "j-1 " << this->distances[k][j-1] << endl;
                    cout << "j " << this->distances[k][j] << endl;
                }
                int swap = this->kNN[k][j];
                this->kNN[k][j] = this->kNN[k][j-1];
                this->kNN[k][j-1] = swap;
                j = j - 1;
            }
        }
    }
};
