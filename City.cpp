#include <math.h> // pow, sqrt etc
#include <string>

/* Header files */
#include "City.h"

using namespace std;

City::City(int vertex_in, float x_in, float y_in){
    vertex = vertex_in;
    x = x_in;
    y = y_in;
}

float City::getX(){ return x;}
float City::getY(){ return y;}
float City::getVertexNum(){ return vertex;}

// calc distance between this city and neighbor city
float City::dist(City neighbor){
float xdist = neighbor.getX() - x;
    float ydist = neighbor.getY() - y;
    return  sqrt(pow(xdist,2) + pow(ydist,2));
}

