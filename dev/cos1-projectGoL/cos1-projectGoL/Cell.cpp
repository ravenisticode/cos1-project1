#include "Cell.h"

Cell::Cell() : isAlive(false) {}

void Cell::setAlive(bool alive) {
    isAlive = alive;
}

bool Cell::getAlive() const {
    return isAlive;
}

char Cell::getASCII() const {
    return isAlive ? 'X' : '.';
}
