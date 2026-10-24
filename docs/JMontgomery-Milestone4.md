# Milestone 4 - Final Development Documentation

## ⚙️ Final Features Added
* **Dynamic Parameter Validation Enforcer:** Upgraded the command terminal interface loop to systematically sweep user string inputs character-by-character, explicitly verifying data safety before parsing configurations.
* **Toroidal Edge-Wrapping Engine:** Fully synchronized modular neighbor evaluations using modulo constraints (`%`), ensuring that automated cell columns wrap seamlessly across border intersections without causing array indexing gaps.

## 🧹 Refactoring Improvements
* **Private Allocation Abstraction Layer:** Extracted bare matrix operations out of the standard constructor and into a single memory block pipeline (`allocateMemory` and `freeMemory`). This completely insulates array definitions and ensures deep cleaning of heap objects.
* **Constant Parameter Passing (`const&`):** Upgraded class lookups and copy references to utilize explicit constant references, completely eliminating large hidden string-copy overhead within execution stacks.

## 🐛 Bug Fixes
* **Input Buffer Skip Patch:** Swapped raw `std::cin.get()` mechanics out for a standalone string capture sequence using `std::getline`. This cleanly clears out trailing newline characters (`\n`), stopping the simulation engine from skipping iterations.
* **Partial Alphanumeric Bypass Correction:** Fixed an issue where string-to-integer utilities (`std::stoi`) would inadvertently parse broken inputs like `"5abc"`. The validation filter now safely blocks all strings containing mixed alphabetic parameters.

## ✨ Usability Updates
* **Defensive Range Boundaries:** Implemented strict numerical bounding checks on row, column, and generation inputs. The system now enforces a positive minimum grid layout of `3x3` and caps allocations at `100x100` to prevent memory allocation crashes.
* **Graceful Exception Staging:** Replaced terminal application crash states with user-friendly looping alerts, printing explicit error limits and requesting clean values without forcing a console reload.
