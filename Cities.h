#ifndef __Cities_H_INCLUDED__
#define __Cities_H_INCLUDED__
#include <vector>
using namespace std;
class Cities{
    public:
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
                static float distsq(City i, City j);
        };
        Cities(istream& reader);
        int ds(int i, int j);
        int tourDist(vector<int> &tour);
        int getNumCities();
        int getNNSize();
        void findkNN();
        vector< vector<int> > kNN;
    private:
        static int dist(City i, City j);
        vector<Cities::City> listCities;
        vector< vector<int> > distances;
        int numCities;
};
#endif
