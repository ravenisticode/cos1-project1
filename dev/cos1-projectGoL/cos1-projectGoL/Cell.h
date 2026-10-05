#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;

public:
    Cell();
    void setAlive(bool alive);
    bool getAlive() const;
    char getASCII() const; // Returns 'X' for alive, '.' for dead
};

#endif
