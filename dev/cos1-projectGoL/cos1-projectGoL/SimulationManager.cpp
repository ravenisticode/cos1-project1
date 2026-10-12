#include "SimulationManager.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib> // Needed for std::system stuffs

SimulationManager::SimulationManager(int rows, int cols)
    : simulationGrid(rows, cols), currentGeneration(0), isRunning(false) {
}

void SimulationManager::startSimulation() {
    int choice = 0;

    while (choice != 3) {
        // Clear console for a clean UI aesthetic
#ifdef _WIN32
        std::system("cls");
#else
        std::cout << "\x1B[2J\x1B[H";
#endif

        std::cout << "===== CONWAY'S GAME OF LIFE (ASCII) =====\n";
        std::cout << "1. Run Simulation Grid\n";
        std::cout << "2. View Project Information & Rules\n";
        std::cout << "3. Exit Application\n";
        std::cout << "=========================================\n";
        std::cout << "Enter selection (1-3): ";

        // Input Validation
        if (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\n[!] Invalid input. Press Enter to try again...";
            std::cin.get();
            continue;
        }

        if (choice == 1) {
            // Run the actual simulation loop
            isRunning = true;
            currentGeneration = 0;
            simulationGrid.initializeRandom();

            while (isRunning && currentGeneration < 5) {
        #ifdef _WIN32
                std::system("cls");
        #else
                std::cout << "\x1B[2J\x1B[H";
        #endif

                std::cout << "--- Conway's Game of Life: ASCII Edition ---\n";
                std::cout << "Generation: " << currentGeneration << "\n\n";
                simulationGrid.printGrid();

                updateGeneration();
                currentGeneration++;

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

            std::cout << "\nSimulation paused or completed. Press Enter to return to menu...";
            std::cin.ignore(1000, '\n');
            std::cin.get();

        }
        else if (choice == 2) {

            // Display game rules cleanly

        #ifdef _WIN32
            std::system("cls");
        #else
            std::cout << "\x1B[2J\x1B[H";
        #endif
            std::cout << "=== CONWAY'S GAME OF LIFE RULES ===\n\n";
            std::cout << "1. Underpopulation: Alive cell with < 2 alive neighbors dies.\n";
            std::cout << "2. Survival: Alive cell with 2 or 3 alive neighbors lives.\n";
            std::cout << "3. Overpopulation: Alive cell with > 3 alive neighbors dies.\n";
            std::cout << "4. Reproduction: Dead cell with exactly 3 alive neighbors becomes alive.\n\n";
            std::cout << "Press Enter to return to the main menu...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
        }
    }
    std::cout << "\nThank you for using the simulation. Goodbye!\n";
}

void SimulationManager::updateGeneration() {
    // Stub function where my 4 core Conway rules will execute next milestone
}
