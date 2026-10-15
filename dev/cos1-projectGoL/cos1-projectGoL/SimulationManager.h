#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "Grid.h"

class SimulationManager {
private:
    Grid* gameBoard; // Pointer to our grid object
    int maxGenerations;
    int currentGeneration;

public:
    SimulationManager();
    ~SimulationManager();

    void run(); // Main engine control loop
};

#endif
