#ifndef GRID_H
#define GRID_H

class Grid {
private:
    int width;
    int height;
    bool** currentGrid; // Pointer to the active generation array
    bool** nextGrid;    // Pointer to the buffer array for calculation

public:
    Grid(int w, int h);
    ~Grid(); // Destructor to clean up heap allocations

    void initializeRandom(float density);
    int countAliveNeighbors(int row, int col) const;
    void updateGeneration();
    void display() const;
};

#endif
