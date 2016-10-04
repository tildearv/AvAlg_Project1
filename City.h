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
        float dist(City neighbor);
};
