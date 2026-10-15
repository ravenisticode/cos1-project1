#include "SimulationManager.h"
#include <iostream>
#include <string>

// Helper validation function inside our manager's source file
int getValidatedInput(const std::string& prompt) {
    std::string userInput;
    int choice = 0;
    bool isValid = false;

    while (!isValid) {
        std::cout << prompt;
        std::getline(std::cin, userInput);

        try {
            choice = std::stoi(userInput);
            if (choice <= 0) throw std::out_of_range("Must be positive");
            isValid = true;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Error: Invalid text string. Numbers only.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Error: Out of range bounds. Try a smaller positive number.\n";
        }
    }
    return choice;
}

SimulationManager::SimulationManager() {
    gameBoard = nullptr;
    maxGenerations = 0;
    currentGeneration = 0;
}

SimulationManager::~SimulationManager() {
    // Safely delete the dynamically allocated grid object to prevent leaks
    if (gameBoard != nullptr) {
        delete gameBoard;
    }
}

void SimulationManager::run() {
    std::cout << "=== Conway's Game of Life: ASCII Edition ===\n\n";

    int width = getValidatedInput("Enter grid width: ");
    int height = getValidatedInput("Enter grid height: ");
    maxGenerations = getValidatedInput("Enter number of generations to run: ");

    // Instantiating our Grid using a pointer on the heap
    gameBoard = new Grid(width, height);
    gameBoard->initializeRandom(0.3f);
    gameBoard->display();

    for (currentGeneration = 1; currentGeneration <= maxGenerations; ++currentGeneration) {
        std::cout << "Generation " << currentGeneration << " of " << maxGenerations << ". Press Enter to evolve...";
        std::cin.get(); // Wait for user press

        gameBoard->updateGeneration();
        gameBoard->display();
    }

    std::cout << "Simulation completed safely. Goodbye!\n";
}
