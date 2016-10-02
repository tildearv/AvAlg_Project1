#include <fstream>
#include <iostream>
#include <vector>
#include "City.cpp"

using namespace std;


vector<City> buildNodes(){
    ifstream reader("./samples/tsp.in");
        string line;
        getline(reader, line);
        int numCities = stoi(line);
        vector<City> cities;
        for(int i = 0; i < numCities; i++){
            getline(reader, line);
            int index = line.find(" ", 0);
            float x = stod(line.substr(0,index));
            float y = stod(line.substr(index,line.length()));
            City city(x,y);
            cities.push_back(city);
        }
        reader.close();
    return cities;
}






int main() {
    vector<City> cities = buildNodes();
    return 0;
}
