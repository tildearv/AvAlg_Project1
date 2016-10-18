#ifndef __City_H_INCLUDED__
#define __City_H_INCLUDED__
#include <vector>
using namespace std;
class City{
    private:
        // store coordinates
        float x;
        float y;
        int vertex; // vertex num
    public:
        City(int vertex, float x, float y);
        float getX();
        float getY();
        float getVertexNum();
        float dist(City neighbor);
        static float distsq(City i, City j);
};
#endif
