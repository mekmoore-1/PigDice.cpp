#include <random>
#include "DIE.h"

   Die::Die() {
       dieValue = 1;
       numOfSides = 6;

       setDieValue();

   }
// setter for die value
void Die::setDieValue() {
       dieValue = rand() % numOfSides + 1;
   }
// getter for die value
int Die::getDieValue() {
       return dieValue;
   }
// setter for sides
void Die::setNumOfSides(int Sides) {
       if (Sides == 4 || Sides == 6 || Sides == 8) {
           numOfSides = Sides;
       }
   }
// getter for sides
int Die::getNumOfSides() {
       return numOfSides;
   }
