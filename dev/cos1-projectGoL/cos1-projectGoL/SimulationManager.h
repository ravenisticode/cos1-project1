#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "Grid.h"

class SimulationManager {
private:
    Grid simulationGrid;
    int currentGeneration;
    bool isRunning;

public:
    SimulationManager(int rows, int cols);
    void startSimulation();
    void updateGeneration();
};

#endif
