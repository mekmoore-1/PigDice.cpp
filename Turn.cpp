//Mekhi
#include <iostream>
#include "Turn.h"
#include "PDGame.h" // 8.

struct GameState;

Turn::Turn() {
     m_turnCount = 0;
     m_ScoreThisTurn = 0;
     m_turnOver = false;
     m_choice = '\0';
}
//6.
void Turn::setParentGame(PDGame* parentGame) {
     m_parentGame = parentGame;
}
void Turn::takeTurn() {
     m_turnCount++;
     std::cout << "\n\nTURN " << m_turnCount;
     //ISSUE: Turn object "part" needs access to m_gameScore in "whole" (PDGame)
     std::cout << " - Game Score: " << m_parentGame->getGameScore(); //9.
     while (!m_turnOver) {
          std::cout << "\nroll or hold? (r/h):";
          std::cin >> m_choice;
          if (m_choice == 'r') {
               roll();
          }
          else if (m_choice == 'h') {
               m_turnOver = true;
          }
          else {
               std:: cout << "Invalid choice!";
          }
     }
     std::cout << "Score Banked This Turn" << m_turnCount;
}
int Turn::getScoreThisTurn() const {
     return m_ScoreThisTurn;
}
void Turn::resetTurnOver() {
     m_turnOver = false;
}
int Turn::getTurnCount()  {
     return m_turnCount;
}
void Turn::resetScoreThisTurn() {
     m_ScoreThisTurn=0;
}
void Turn::roll() {
     m_myDie.rollDie();
     std::cout << "DIE: " << m_myDie.getDieValue();
     if (m_myDie.getDieValue()==1) {
          std::cout << "\nTurn over. No score. \n";
          m_ScoreThisTurn = 0;
          m_turnOver = true;
     }
     else {
          m_ScoreThisTurn+=m_myDie.getDieValue();
          std::cout << " - Running score this turn:" << m_ScoreThisTurn;
     }
}