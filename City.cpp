#include <string>
#include <math.h> // pow, sqrt etc

using namespace std;


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
