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


 Overview

This week, I shifted my focus from project setup into active implementation for my ASCII Conway's Game of Life. I successfully designed and completed a detailed Milestone 2 project planning worksheet, recorded a prototype overview video, and built out the core state machine for the application's user interface.

:cactus: Challenges

My primary obstacle this week was preventing user interface breaks and system memory faults. If a user entered non-numeric input into the menu loops, it would cause infinite execution loops. Additionally, checking cell neighbors along the absolute borders of my 2D matrix threatened out-of-bounds index errors that would crash the entire application.

:trophy: Accomplishments

I leveled up significantly in both input validation safety and algorithm design! I successfully updated my SimulationManager with input-clearing routines that handle malicious keystrokes cleanly. I also implemented a cross-platform console clearing routine to animate frames in place, and successfully coded a toroidal edge-wrapping system in Grid.cpp using the mathematical modulo operator (%).

:crystal_ball: Next Steps

Before Week 3, I will prioritize moving the engine from a static grid state into a functional double-buffering pipeline. This will ensure that cellular survival and birth rules calculate simultaneously across a secondary hidden matrix before updating the active display grid.








