# AvAlg_Project1

To run: ./main.o < "./samples/tsp.in"
g++ -std=c++11 -o main.o main.cpp NearestNeighbou.cpp twoOpt.cpp Cities.cpp TabuSearch.cpp

#Tour construction heuristic
##Nearest Neighbor
    Implemented naive O(n^2)
    TODO: k-d tree
#Exchange heuristic
##2-opt
    Done, might need to be better
#Held-Karp lowe bound
#Test case
    Found TSPLIB
#Lin–Kernighan heuristic
#Do some kind of graphics
#Simulated Annealing!
    Get it out of local min
