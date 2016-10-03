#include <string>
<<<<<<< HEAD
#include <math.h>
#include "City.h"
=======
#include <math.h> // pow, sqrt etc
>>>>>>> 3fc56547e17f5056ccfd0af56fd1dd06d1fcade0

using namespace std;

City::City(int vertex_in, float x_in, float y_in){
    vertex = vertex_in;
    x = x_in;
    y = y_in;
}
float City::getX(){ return x;}
float City::getY(){ return y;}
float City::getVertexNum(){ return vertex;}
float City::dist(City neighbor){
float xdist = neighbor.getX() - x;
    float ydist = neighbor.getY() - y;
    return  sqrt(pow(xdist,2) + pow(ydist,2));
}

<<<<<<< HEAD
=======
class City{
    private:
        // store coordinates
        float x;
        float y;
        int vertex; // vertex number
    public:
        City(int vertex, float x, float y){
            this -> vertex = vertex;
            this -> x = x;
            this -> y = y;
        }
        float getX(){ return x;}
        float getY(){ return y;}
        float getVertexNum(){ return vertex;}

        // calc distance between this city and neighbor city
        float dist(City neighbor){
            float xdist = neighbor.getX() - x;
            float ydist = neighbor.getY() - y;
            return  sqrt(pow(xdist,2) + pow(ydist,2));
        }
};
>>>>>>> 3fc56547e17f5056ccfd0af56fd1dd06d1fcade0
