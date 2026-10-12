#include "Grid.h"
#include <iostream>

Grid::Grid(int r, int c) : rows(r), cols(c) {
    matrix.resize(rows, std::vector<Cell>(cols));
}

void Grid::initializeRandom() {

    // Basic hardcoded live cells for initial milestone verification
    if (rows > 2 && cols > 2) {
        matrix[1][1].setAlive(true);
        matrix[1][2].setAlive(true);
        matrix[1][3].setAlive(true); // Blinker pattern
    }
}

void Grid::printGrid() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j].getASCII() << " ";
        }
        std::cout << "\n";
    }
}

int Grid::countAliveNeighbors(int r, int c) const {
    int aliveCount = 0;

    // Check all 8 surrounding cells (-1 to +1 directional offsets)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Skip checking the center cell itself<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            if (i == 0 && j == 0) continue;

            // Toroidal Edge Wrapping (The Modulo Trick)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            // This safely connects the left edge to the right edge, and top to bottom!<<<<<<<<<

            int neighborRow = (r + i + rows) % rows;
            int neighborCol = (c + j + cols) % cols;

            if (matrix[neighborRow][neighborCol].getAlive()) {  // One great big fat huge matrix "if" going here<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                aliveCount++;
            }
        }
    }
    return aliveCount;
}
