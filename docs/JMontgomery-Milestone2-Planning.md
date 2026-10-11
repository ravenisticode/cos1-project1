> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Conway's Game of Life
  
**What does your program currently do? (1–3 sentences)**   
→ Currently, my application initializes an object-oriented foundation consisting of three interconnected classes that manage a terminal-based 2D grid matrix. Users can navigate a responsive main menu system featuring robust input validation and view a clear informational screen detailing the core simulation rules. When launched, the engine outputs generation frames cleanly in place by utilizes platform-specific escape codes to refresh the console view, while running a newly integrated 8-way toroidal neighbor-counting function behind the scenes.

---

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   The object-oriented class infrastructure (`Cell`, `Grid`, and `SimulationManager`) is fully established and communicating correctly. The program boots into a polished main menu featuring robust user input validation and an informational rules screen, while the core loop cleanly utilizes console escape codes to refresh frames in place without scrolling text down the screen. Additionally, the 8-way toroidal neighbor-counting mathematical algorithm is fully written and correctly maps wrap-around grid boundary checks without throwing memory out-of-bounds crashes.
  
**What is NOT working or incomplete?**   
→   The 4 primary survival, death, and reproduction rules of Conway's Game of Life are currently incomplete and sitting inside an empty placeholder stub function in `SimulationManager::updateGeneration()`. Furthermore, the double-buffering vector swapping mechanic needs to be engineered so that cell states compute simultaneously across the matrix rather than overwriting each other sequentially mid-frame.
  
**What feels confusing or messy in your code?**   
→ Managing multi-dimensional vector arrays (`std::vector<std::vector<Cell>>`) across multiple separate header and implementation files can occasionally feel a bit structurally cluttered. Specifically, ensuring that the `SimulationManager` updates and copies the grid arrays efficiently each generation without slowing down or creating redundant matrix copies feels like the messiest logistical optimization problem right now.

---

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Core Cellular Automata Rules Engine
  
**What does this feature do?**   
→   It evaluates the active cell grid states synchronously using Conway's 4 fundamental laws: underpopulation, survival, overpopulation, and reproduction.
  
**Why is this feature important?**   
→   This is the mathematical heart of the entire application. Without evaluating neighbor counts to trigger live births and deaths, the simulation remains completely static.
  
---
### Feature 2  
**Name:**   
→   Double Buffering Generation Pipeline
  
**What does this feature do?**   
→   It creates secondary, hidden 2D vector matrix to store upcoming cell transformations temporarily before copying them back to the active display grid.
  
**Why is this feature important?**   
→   It ensures all cells change states at the exact same moment. Without it, cell changes calculate sequentially, meaning updated cells ruin neighbor evaluations for adjacent cells mid-frame.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Interactive Pattern Library Preset Seeding Menu
  
**What does this feature do?**   
→   It adds a selection menu that pre-seeds the simulation grid with legendary stable configurations like Blinker Oscillators or Glider Spaceships.
  
**Why is this feature important?**   
→   It lets users immediately observe complex, moving cellular behaviors instead of relying entirely on pure randomness.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   No new classes are needed. The three existing classes (`Cell`, `Grid`, and `SimulationManager`) are complete enough to scale and support these updates.
  
**Will you modify any existing classes? How?**   
→   Yes. I will update `SimulationManager` to execute the double-buffering vector state swaps and rules processing inside `updateGeneration()`, and modify the menu flow to handle preset selection configurations.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   Standard 2D vectors (`std::vector<std::vector<Cell>>`) to represent the twin memory buffer matrices.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   The main terminal panel clears, displaying a welcome banner alongside 3 distinct menu selections.
2. User chooses →   Option 1 to start a simulation session, Option 2 to view rules data, or Option 3 to terminate execution.
3. Program responds →   Clearing old terminal data, routing input to correct helper classes, and executing loops smoothly in place.
4. Loop/next step →   After a simulation completes, the terminal requests an Enter keystroke to route back to the central hub without dead ends.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Adding uniform brackets around entry targets (e.g., `Enter selection [1-3]:`) to establish a professional interface look.
  
- Better error handling:   
→   Utilizing `cin.clear()` and `cin.ignore()` loops to explicitly isolate alphabetic input failures so typing characters doesn't trigger endless terminal scrolls.
  
- Improved menu/navigation:   
→   Adding pause-and-return checkpoints at every window endpoint so data stays readable until the user explicitly requests a menu jump.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Designing the double buffering generation pipeline cleanly so that swappings matrices doesn't create excessive data copies or cause circular references across our files.
  
**What is your plan if you get stuck?**   
→   Review the multi-dimensional tracking lectures, test individual rule behaviors using a microscopic 3x3 test array scratchpad, and drop lines to the instructor early on Discord if a logic loop starts crashing.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Dynamic Matrix State Optimization and Array Loop Logic.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   I will study professional multi-dimensional layout tutorials, carefully inspect compiler warnings in Visual Studio, and research how real-time rendering pipelines structure back-buffer page swapping.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- `[UI] Integrate input text filtering loops to drop character type assignment errors`
- `[Logic] Build a temporary grid back-buffer inside SimulationManager for simultaneous evaluation`
- `[Logic] Map the four core rules of Conway's cellular mechanics inside state processes`
- `[Feature] Write pre-seeded structural coordinate maps for Gliders and Blinker oscillators`
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.