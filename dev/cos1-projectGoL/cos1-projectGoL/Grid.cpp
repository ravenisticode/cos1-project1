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
    // Stub function to be fully implemented next week
    return 0;
}
