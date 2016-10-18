#ifndef __City_H_INCLUDED__
#define __City_H_INCLUDED__
class City{
    private:
        // store coordinates
        float x;
        float y;
        int vertex; // vertex num
        vector<int> nearest;
    public:
        City(int vertex, float x, float y);
        float getX();
        float getY();
        float getVertexNum();
        float dist(City neighbor);
};
