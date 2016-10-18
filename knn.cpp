#include <vector>
#include "City.h"

using namespace std;
vector<vector<int> > knn(vector<City> cities, int nnMax){

    /*  This solution assumes cities is ordered so that cities[k] has */
    /* vertexnum k.                                                   */

    /* Parameters for  finding the  city with largest  distance. */
    int largest = -1;
    int swap = -1; // swap index of the city with largest dist
    vector<vector<int> > nnMatrix;

    /* loop through every city */
    for (int i = 0; i < cities.size(); i++){
        int m = 0;

        /* for every city, save the mth neighbor */
        for (int j = 0; j < cities.size(); j++){

            /* skip if we look at the same city */
            if ( j == i){
                continue;
            }

            float thisdist = City::distsq(cities[i], cities[j]);

            /* if we have not found nnMax neighbors, just put cities */
            if( m < nnMax ){
                nnMatrix[i][m] = j;
                /* keep track of the city with biggest distance */
                if (thisdist > largest ){
                    largest = thisdist;
                    swap = m;
                }
                m++;
            }else if (thisdist < largest){
                /* nnMax numbers of neighbors to city i */
                /* swap is indx of city with biggest distance */

                /* swap since city j is closer to city i */
                nnMatrix[i][swap] = j;
                largest = -1;

                /* find city with largest dist to city i */
                for (int k = 0; k < nnMax; k++){
                    City cityk = cities[nnMatrix[i][k]];
                    float distk = City::distsq(cities[i], cityk);
                    if (distk > largest){
                        largest = distk;
                        swap = k;
                    }
                }
            }
        }
    }
    return nnMatrix;
}
