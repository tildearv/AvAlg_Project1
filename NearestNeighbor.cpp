#include <limits> // max float
#include <time.h> // used for random
#include <vector>
using namespace std;

/* Tour  construction heuristic.  Input  is an  array  of all  cities */
/* outputs a tour.                                                    */

vector<int> nearestNeighbor(vector<City> cities){

    vector<int> tour;

    // take some random vertex
    srand (time(NULL));
    int rnd = rand() % cities.size();

    City current = cities[rnd]; // creates city

    // put in the first city and delete it from cities
    tour.push_back(current.getVertexNum());
    cities.erase(cities.begin() + rnd);

    // some variables to keep track of best
    float best = numeric_limits<float>::max();
    int best_ind = -1;


    while(cities.size() > 0){
        for(int i=0; i!=cities.size(); ++i){
            // calc distance between current and city[i]
            float dist = current.dist(cities[i]);
            if (dist < best){
                best = dist;
                best_ind = i;
            }
        }
        // erase best city and set it to current
        current = cities[best_ind];
        cities.erase(cities.begin() + best_ind);
        tour.push_back(current.getVertexNum());

        best = numeric_limits<float>::max();
    }
    return tour;
}
