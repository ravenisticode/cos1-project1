# Milestone 3 Documentation - Conway's Game of Life

## ⚙️ Features Added
- **Dynamic Pseudo-Random Generation**: Upgraded `initializeRandom()` from using a static, hardcoded template pattern to a dynamic seed loop using `std::rand()` and custom density thresholds.
- **Rule Engine & Execution Pacing**: Fully implemented Conway's four rules of cellular automaton within the simulation sequence. Integrated terminal frame stops so the simulation waits for a user keyboard strike before evolving to the next generation step.

## 🧱 Updates to Your System Design
- **Object Encapsulation (`Cell**`)**: Shifted the primary array matrix from a raw 2D array of booleans over to a dedicated 2D matrix of encapsulated `Cell` class objects managed entirely on the heap.
- **Three-Phase Generation Loop**: Separated cell state mutation into explicit sequential phases: neighbor aggregation, future state staging (`setNextState`), and simultaneous world evolution (`evolve()`). This architecture cleanly prevents calculation skewing.

## 🧹 Refactoring Improvements & What Changed
- **Input Validation Stability**: Removed unstable, raw `std::cin >>` data ingestion streams. Replaced them inside `SimulationManager.cpp` with a centralized string evaluation pipeline using `std::getline` and `std::stoi`.
- **Exception Shielding Block**: Nested the string parsing within a structured `try/catch` block explicitly handling `std::invalid_argument` and `std::out_of_range` triggers. This completely eliminates infinite application loop locks when letters or symbols are submitted to numerical fields.
- **Clean Memory Architecture**: Implemented robust constructor deep allocation and explicit destructor loops across the `Grid` and `SimulationManager` wrapper layers to clean up memory footprints on exit.