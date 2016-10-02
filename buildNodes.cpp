#include <iostream>
#include <fstream>

using namespace std;



void buildNodes(){
    ifstream reader("tsp.in");
    if(!reader){
        cout << "Error opening file" << endl;
    }else{
        string line;
        getline(reader, line);
        int cities = stoi(line);
        for(int i = 0; i < cities; i++){
            getline(reader, line);
            int index = line.find(" ", 0);
            float x = stod(line.substr(0,index));
            float y = stod(line.substr(index,line.length()));
            /* TODO: create nodes */
        }
        reader.close();
    }
}



int main() {
    buildNodes();
    return 0;
}