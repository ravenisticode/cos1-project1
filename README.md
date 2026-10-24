# 🚀 Welcome to Project & Portfolio!

This repository will be used to keep track of research and development conducted in this class. Follow the instructions below to get started.
cos
### Getting Started

**1.** Review the [About](./docs/01_about/README.md) README and all of the links it provides.

**2.** Review the documentation and [Getting Started](./docs/02_getting_started/README.md) steps in this repository's docs folder.

**3.** Attend the first Live Lecture to see a live setup demo. If you are unable to attend, make sure to watch the archive.

### Next Steps...

After completing the above steps, feel free to begin updating this readme where indicated below. Remember to update this document each week to receive proper credit for the weekly Milestone assignment.

<br>

> ❗️ &nbsp; Now that you have read to this point, go ahead and delete this sentence and everything above it.

<br>

# Project & Portfolio 1

### Jason Montgomery

Hello my name is [Jason Montgomery]. I am a student from [Tucson, AZ]. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Replace this paragraph with your stand up for this week. Use the prompts above to summarize your most recent milestone activity and work.

### Week 2

My next stand up will go here...

### Week 3

Progress Update • Completed: Established the object-oriented layout, built the ASCII rendering loop, and completed the logic to count adjacent neighbors. • In Progress: Implementing Conway's rules inside updateGeneration(). Setting up a double-buffered pointer-swapping array system (bool**) to include pointer utilization. • To Do: Implement the lecture-recommended, crash-proof string extraction method for menu inputs. • Challenges: My original implementation relied on raw std::cin >> formatting, which caused infinite loops when receiving invalid text inputs. Refactoring Plan • Target Area: Input Validation and Random Initialization. • Why: The old validation routines do not handle exceptions gracefully, risking runtime crashes. The random setup also relies on a hardcoded test pattern instead of dynamic generation. • Action Plan: I will rewrite the terminal parsing pipeline to use std::getline paired with std::stoi nested inside a try/catch block to filter out invalid characters and handle exceptions cleanly. Level Up Goal • Focus: Advanced Pointer Manipulation & Memory Operations. • Steps: Reviewing Day 3 Lecture examples on raw pointer allocation and deploying a three-step pointer variable swap to execute buffer updates efficiently without deep-copying memory. Optional Project Feedback • I am using an array of pointers (bool**) to handle my double-buffering. Is it cleaner from a class design perspective to encapsulate the buffer pointer swap directly within the Grid class update function, or should that assignment loop be handled by the main application controller?"

### Week 4

# Conway's Game of Life: ASCII Edition

## 🔎 Overview
This week, I brought the C++ engine architecture from a standard working state to an optimized, crash-proof console application. I successfully stabilized memory allocation routines, hardened the application user layer, and wrapped up our final code sprint objectives.

## 🧹 Project Wrap-Up
Before submitting the final application, I focused completely on defensive systems engineering and software robustness. I engineered validation sweeps to intercept mixed data string vulnerabilities (like "5abc"), added bounded limits to block zero or negative inputs from touching heap memory, and fixed a lingering input buffer bug that was causing iterations to skip generations.

## 🧟 Challenges
My biggest technical obstacle was preventing potential memory leakage and double-free vulnerabilities within our dynamic multidimensional matrix when objects were processed or re-initialized. I resolved this by auditing our `Grid` architecture, separating structural pointers into private helpers, and writing an explicit Deep Copy Constructor and Copy Assignment Operator under the C++ Rule of Three.

## 🏆 Biggest Takeaway
The most valuable lesson I learned this month is the massive difference between simply typing code until it compiles and cleanly tracking an application using structured version control. Transitioning to an industry workflow using decoupled Git branches, distinct Issues, and a Project board allowed me to isolate complex memory interactions systematically instead of chasing cascading bugs.

## 🔮 Future Development
If I continue expanding this application, my next priority would be adding external file-system integration to let the interpreter parse and read custom initial matrix configurations directly from local `.cells` or `.txt` files. I would also love to implement multi-threaded iteration tracks to optimize cell generation calculation speeds on larger display fields.

