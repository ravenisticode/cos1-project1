#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor: Dynamically allocate memory for both pointer arrays on the heap
Grid::Grid(int w, int h) : width(w), height(h) {
    currentGrid = new bool* [height];
    nextGrid = new bool* [height];
    for (int i = 0; i < height; ++i) {
        currentGrid[i] = new bool[width] {false};
        nextGrid[i] = new bool[width] {false};
    }
}

// Destructor: Safely clean up raw pointers to prevent memory leaks
Grid::~Grid() {
    for (int i = 0; i < height; ++i) {
        delete[] currentGrid[i];
        delete[] nextGrid[i];
    }
    delete[] currentGrid;
    delete[] nextGrid;
}

// TRUE RANDOM INITIALIZATION: Replaces the hardcoded pattern
void Grid::initializeRandom(float density) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            float roll = static_cast<float>(std::rand()) / RAND_MAX;
            currentGrid[row][col] = (roll < density);
            nextGrid[row][col] = false; // Keep the buffer clean
        }
    }
}

// NEIGHBOR COUNTING: Uses modulo wrapping so cells smoothly cross screen borders
int Grid::countAliveNeighbors(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the target cell itself

            // Modulo formula ensures edges wrap around seamlessly
            int targetRow = (row + i + height) % height;
            int targetCol = (col + j + width) % width;

            if (currentGrid[targetRow][targetCol]) {
                count++;
            }
        }
    }
    return count;
}

// SIMULATION ENGINE: Evaluates rules and executes the pointer swap
void Grid::updateGeneration() {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int neighbors = countAliveNeighbors(row, col);
            bool isAlive = currentGrid[row][col];

            if (isAlive) {
                // Survival rules
                nextGrid[row][col] = (neighbors == 2 || neighbors == 3);
            }
            else {
                // Reproduction rule
                nextGrid[row][col] = (neighbors == 3);
            }
        }
    }

    // MEANINGFUL POINTER SWAP: Swaps memory addresses instantly
    bool** temp = currentGrid;
    currentGrid = nextGrid;
    nextGrid = temp;
}

// RENDER LOOP: Prints ASCII representation to the console
void Grid::display() const {
    // Clear screen terminal command (Platform-dependent alternate: std::cout << "\x1B[2J\x1B[H";)
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            std::cout << (currentGrid[row][col] ? "# " : ". ");
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
