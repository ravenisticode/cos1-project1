#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
private:
    int width;
    int height;
    Cell** cellMatrix; // A 2D array of Cell objects on the heap

public:
    Grid(int w, int h);
    ~Grid(); // Destructor cleans up the Cell objects safely

    void initializeRandom(float density);
    int countAliveNeighbors(int row, int col) const;
    void updateGeneration();
    void display() const;
};

#endif
