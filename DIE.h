#ifndef PIGDICE_CPP_DIE_H
#define PIGDICE_CPP_DIE_H


class Die {
private:
    int dieValue;
    int numOfSides;

public:
    Die();

    void setDieValue();
    int getDieValue();

    void setNumOfSides(int Sides);
    int getNumOfSides();
};

#endif
