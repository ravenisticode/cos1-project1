#include "SimulationManager.h"
#include <iostream>
#include <thread>
#include <chrono>

SimulationManager::SimulationManager(int rows, int cols)
    : simulationGrid(rows, cols), currentGeneration(0), isRunning(false) {
}

void SimulationManager::startSimulation() {
    isRunning = true;
    simulationGrid.initializeRandom();

    std::cout << "--- Conway's Game of Life: ASCII Edition ---" << std::endl;

    while (isRunning && currentGeneration < 5) {
        std::cout << "\nGeneration: " << currentGeneration << "\n";
        simulationGrid.printGrid();

        updateGeneration();
        currentGeneration++;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void SimulationManager::updateGeneration() {
    // Stub function where my 4 core Conway rules will execute next milestone
}
