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
                static int dist(City i, City j);
                static float distsq(City i, City j);
        };
        Cities(istream& reader);
        int distance(int i, int j);
        int tourDist(vector<int> tour);
        int getNumCities();
        void findkNN();
    private:
        vector<Cities::City> listCities;
        vector< vector<int> > distances;
        vector< vector<int> > kNN;
        void sortkNN();
        int numCities;
};
#endif
