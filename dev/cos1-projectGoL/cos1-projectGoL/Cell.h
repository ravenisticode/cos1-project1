#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;
    bool nextAliveState;

public:
    Cell();

    bool getIsAlive() const;
    bool getNextState() const; // <-- Added this getter
    void setIsAlive(bool state);

    void setNextState(bool state);
    void evolve();
};

#endif
