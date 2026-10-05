# Conway's Game of Life (ASCII Edition)

## 🔎 Overview
This week, I focused on initializing the basic multi-file project architecture for the simulation in the `/dev` folder. I set up the initial class templates for `Grid`, `Cell`, and `SimulationManager` using separated `.h` and `.cpp` structures, and implemented a functional main console loop capable of clearing and printing a blank grid.

## 🧟 Challenges
*   **Challenge:** Preventing visual screen flickering during high-frequency grid refreshes in the console window.
*   **Solution:** I am implementing double buffering (calculating the next generation on a hidden secondary grid state) and investigating system-efficient string builders or platform-specific console commands to overwrite frames cleanly instead of fully clearing the buffer.

## 🏆 Accomplishments
I leveled up my understanding of mapping logical 2D matrices into unified vector shapes and structuring clean multi-file projects in C++ with separation of concerns.

## 🔮 Next Steps
Before the next milestone, I will prioritize coding the neighbor evaluation logic inside the `Grid` class and validating the basic rulesets (birth, survival, and under/overpopulation death).











