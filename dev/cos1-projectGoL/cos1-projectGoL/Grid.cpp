#include "Grid.h"
#include <iostream>
#include <cstdlib>

// Private helper to allocate cell matrices safely
void Grid::allocateMemory(int targetWidth, int targetHeight) {
    width = targetWidth;
    height = targetHeight;

    cellMatrix = new Cell * [height];
    for (int i = 0; i < height; ++i) {
        cellMatrix[i] = new Cell[width];
    }
}

// Private helper to release matrix layers cleanly without memory leaks
void Grid::freeMemory() {
    if (cellMatrix != nullptr) {
        for (int i = 0; i < height; ++i) {
            delete[] cellMatrix[i];
        }
        delete[] cellMatrix;
        cellMatrix = nullptr;
    }
}

// Constructor
Grid::Grid(int initialWidth, int initialHeight) {
    allocateMemory(initialWidth, initialHeight);
}

// Destructor
Grid::~Grid() {
    freeMemory();
}

// 1. RULE OF THREE: Deep Copy Constructor
Grid::Grid(const Grid& otherGrid) {
    // Allocate a completely fresh memory partition matching dimensions
    allocateMemory(otherGrid.width, otherGrid.height);

    // Individually mirror values over cell-by-cell
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cellMatrix[row][col].setIsAlive(otherGrid.cellMatrix[row][col].getIsAlive());
            cellMatrix[row][col].setNextState(otherGrid.cellMatrix[row][col].getNextState());
        }
    }
}

// 2. RULE OF THREE: Deep Copy Assignment Operator (operator=)
Grid& Grid::operator=(const Grid& otherGrid) {
    // Safeguard against self-assignment anomalies
    if (this == &otherGrid) {
        return *this;
    }

    // Scrub old elements from memory completely
    freeMemory();

    // Map new structures
    allocateMemory(otherGrid.width, otherGrid.height);

    // Populate data deeply
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cellMatrix[row][col].setIsAlive(otherGrid.cellMatrix[row][col].getIsAlive());
            cellMatrix[row][col].setNextState(otherGrid.cellMatrix[row][col].getNextState());
        }
    }

    return *this;
}

void Grid::initializeRandom(float density) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            float roll = static_cast<float>(std::rand()) / RAND_MAX;
            cellMatrix[row][col].setIsAlive(roll < density);
        }
    }
}

int Grid::countAliveNeighbors(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            // Seamless boundary edge wrapping (modulo method)
            int targetRow = (row + i + height) % height;
            int targetCol = (col + j + width) % width;

            if (cellMatrix[targetRow][targetCol].getIsAlive()) {
                count++;
            }
        }
    }
    return count;
}

void Grid::updateGeneration() {
    // Phase 1: Analyze current states and calculate the next state for every cell
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int neighbors = countAliveNeighbors(row, col);
            bool currentlyAlive = cellMatrix[row][col].getIsAlive();

            if (currentlyAlive) {
                cellMatrix[row][col].setNextState(neighbors == 2 || neighbors == 3);
            }
            else {
                cellMatrix[row][col].setNextState(neighbors == 3);
            }
        }
    }

    // Phase 2: Evolve all cells to their new states simultaneously 
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cellMatrix[row][col].evolve();
        }
    }
}

void Grid::display() const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            std::cout << (cellMatrix[row][col].getIsAlive() ? "# " : ". ");
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
