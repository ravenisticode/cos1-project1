#ifndef GRID_H
#define GRID_H

#include "Cell.h" // Ensures the Cell object definitions are visible

class Grid {
private:
    int width;
    int height;
    Cell** cellMatrix; // Your 2D matrix structure targeting Cell instances

    // Private helper methods to streamline clean memory operations
    void allocateMemory(int targetWidth, int targetHeight);
    void freeMemory();

public:
    Grid(int initialWidth, int initialHeight);
    ~Grid();

    // RULE OF THREE: Explicit deep copy handlers
    Grid(const Grid& otherGrid);
    Grid& operator=(const Grid& otherGrid);

    // Core simulation framework
    void initializeRandom(float density);
    int countAliveNeighbors(int row, int col) const;
    void updateGeneration();
    void display() const;
};

#endif // GRID_H

