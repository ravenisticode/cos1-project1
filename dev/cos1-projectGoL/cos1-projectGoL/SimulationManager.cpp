#include "SimulationManager.h"
#include <iostream>
#include <string>
#include <cctype> // Required for std::isdigit

// Upgraded crash-proof validation utility with explicit bounding checks
int getValidatedInput(const std::string& prompt, int minValue, int maxValue) {
    std::string userInput;
    int choice = 0;
    bool isValid = false;

    while (!isValid) {
        std::cout << prompt;
        std::getline(std::cin, userInput);

        // 1. Verify that input strings contain strictly numeric characters
        if (userInput.empty()) {
            std::cout << "Error: Input cannot be empty. Please enter a number.\n";
            continue;
        }

        bool isPureNumbers = true;
        for (char character : userInput) {
            if (!std::isdigit(static_cast<unsigned char>(character))) {
                isPureNumbers = false;
                break;
            }
        }

        if (!isPureNumbers) {
            std::cout << "Error: Invalid text string. Numbers only (no letters or spaces).\n";
            continue;
        }

        try {
            choice = std::stoi(userInput);

            // 2. Implement explicit bounding checks to ensure values fall within safe ranges
            if (choice < minValue || choice > maxValue) {
                std::cout << "Error: Out of allowed bounds. Enter a value between "
                    << minValue << " and " << maxValue << ".\n";
            }
            else {
                isValid = true;
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "Error: Invalid input parsing.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Error: Number is too massive for memory definitions. Try a smaller number.\n";
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
    if (gameBoard != nullptr) {
        delete gameBoard;
    }
}

void SimulationManager::run() {
    bool keepRunning = true;

    while (keepRunning) {
        std::cout << "=== Conway's Game of Life: ASCII Edition ===\n";
        std::cout << "1. Run the Simulator\n";
        std::cout << "2. Explanation of Cellular Automata Rules\n";
        std::cout << "3. Exit Program\n";

        int menuChoice = getValidatedInput("Please enter your choice (1-3): ", 1, 3);

        if (menuChoice == 1) {
            int width = getValidatedInput("Enter grid width (3-100): ", 3, 100);
            int height = getValidatedInput("Enter grid height (3-100): ", 3, 100);
            maxGenerations = getValidatedInput("Enter number of generations to run (1-5000): ", 1, 5000);

            // fix added above and now the rest of choice 1 code remains the same

            // Clean up old board if it exists from a previous run
            if (gameBoard != nullptr) {
                delete gameBoard;
            }

            gameBoard = new Grid(width, height);
            gameBoard->initializeRandom(0.3f);
            gameBoard->display();

            for (currentGeneration = 1; currentGeneration <= maxGenerations; ++currentGeneration) {
                std::cout << "Generation " << currentGeneration << " of " << maxGenerations << ". Press Enter to evolve...";

                // FIX: Use getline to swallow stray characters and flush the stream buffer cleanly
                std::string stepBuffer;
                std::getline(std::cin, stepBuffer);

                gameBoard->updateGeneration();
                gameBoard->display();
            }

            std::cout << "Simulation loop completed.\n\n";

        }
        else if (menuChoice == 2) {
            // Choice 2: Explain the Rules
            std::cout << "\n================= THE RULES OF LIFE =================";
            std::cout << "\n1. Underpopulation: Any live cell with fewer than 2 live neighbors dies.";
            std::cout << "\n2. Survival: Any live cell with 2 or 3 live neighbors lives to the next frame.";
            std::cout << "\n3. Overpopulation: Any live cell with more than 3 live neighbors dies.";
            std::cout << "\n4. Reproduction: Any dead cell with exactly 3 live neighbors becomes alive.";
            std::cout << "\n=====================================================\n\n";

        }
        else if (menuChoice == 3) {
            // Choice 3: Exit
            std::cout << "Exiting system. Goodbye!\n";
            keepRunning = false;
        }
        else {
            std::cout << "Invalid selection. Please choose options 1, 2, or 3.\n\n";
        }
    }
}
