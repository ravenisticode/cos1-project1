#include "Cell.h"

Cell::Cell() {
    isAlive = false;
    nextAliveState = false;
}

bool Cell::getIsAlive() const {
    return isAlive;
}

void Cell::setIsAlive(bool state) {
    isAlive = state;
}

void Cell::setNextState(bool state) {
    nextAliveState = state;
}

void Cell::evolve() {
    isAlive = nextAliveState;
}
bool Cell::getNextState() const {
    return nextAliveState;
}
