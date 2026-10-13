#include <random>
#include "DIE.h"

   Die::Die() {
       m_dieValue=0;
   }
// setter for die value
void Die::rollDie() {
      std::random_device rd;
       std::mt19937 gen(rd());
       std::uniform_int_distribution<int> dis(1,6);
       m_dieValue = dis(gen);
   }
// getter for die value
int Die::getDieValue() const {

      // rules for accessing the data
       return m_dieValue;
   }




