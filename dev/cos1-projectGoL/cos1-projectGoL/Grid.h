#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"

class Grid {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> matrix;

public:
    Grid(int r, int c);
    void initializeRandom();
    void printGrid() const;
    int countAliveNeighbors(int r, int c) const;
};

#endif
