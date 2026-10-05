#include "SimulationManager.h"

int main() {
    // Instantiate the manager with a 10x10 simulation board area
    SimulationManager gameManager(10, 10);
    gameManager.startSimulation();

    return 0;
}
