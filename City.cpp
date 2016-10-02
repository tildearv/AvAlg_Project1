#include <string>
#include <math.h>

using namespace std;


class City{
    private:
        float x;
        float y;
    public:
        City(float x, float y){
            this -> x = x;
            this -> y = y;
        }
        float getX(){ return x;}
        float getY(){ return y;}
        float dist(City neighbor){
            float xdist = neighbor.getX() - x;
            float ydist = neighbor.getY() - y;
            return  sqrt(pow(xdist,2) + pow(ydist,2));
        }
};
