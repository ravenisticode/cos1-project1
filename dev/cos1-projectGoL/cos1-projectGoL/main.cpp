#include <cstdlib>
#include <ctime>
#include "SimulationManager.h"

int main() {
    // Seed the pseudo-random generator exactly once on startup
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Instantiate and boot the manager engine
    SimulationManager manager;
    manager.run();

    return 0;
}
