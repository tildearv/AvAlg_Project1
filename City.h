using namespace std;


class City{
    private:
        float x;
        float y;
        int vertex;
    public:
        City(int vertex, float x, float y);
        float getX();
        float getY();
        float getVertexNum();
        float dist(City neighbor);
};
