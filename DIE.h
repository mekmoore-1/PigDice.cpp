#ifndef PIGDICE_CPP_DIE_H
#define PIGDICE_CPP_DIE_H



class Die {
private:
    int dieValue;
    int numOfSides;

public:
    Die();
    void setNumOfSides(int Sides);
    int getNumOfSides();
    void setDieValue();
    int getDieValue();

};

#endif
