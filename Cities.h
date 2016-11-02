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
        class Ncity {
            public:
                /* dist to neighb city */
                int dist;
                int vertex;
                Ncity(int vertex, int dist);
                bool operator<(const Ncity &nc2) const;
        };
        Cities(istream& reader);
        int ds(int i, int j);
        int tourDist(vector<int> &tour);
        int getNumCities();
        int getNNSize();
        void findkNN();
        vector< vector<Cities::Ncity> > kNN;
        static int dist(City i, City j);
    private:
        vector<Cities::City> listCities;
        vector< vector<int> > distances;
        int numCities;
        int maxNN;
};
#endif
