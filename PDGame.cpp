#include "PDGame.h"

#include <iostream>
#include <ostream>

PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;
    m_myTurn.setParentGame(this); // 7.
    displayRules();
    playGame();
}
int PDGame::getGameScore() const {
    return m_gameScore; //2
}
void PDGame::displayRules() {
    std::cout << "        LET'S PLAY PIG DICE!\n";
    std::cout << "The goal is to get to 20 points.\n";
    std::cout << "See how many turns it takes you!\n\n";

    std::cout << "RULES:\n";
    std::cout << "1. The goal is to reach 20 points.\n";
    std::cout << "2. A turn ends when you hold or roll a 1.\n";
    std::cout << "3. If you roll a 1, you lose all points\n";
    std::cout << "   earned during that turn.\n";
    std::cout << "4. If you hold, you bank all points\n";
    std::cout << "   earned during the turn.\n";
    std::cout << "5. Try to reach 20 points in as few\n";
    std::cout << "   turns as possible!\n";

}

void PDGame::playGame() {
    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gameOver = true;
        }
        else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }
        std::cout <<"\n\nYou finished with a final score of ";
        std::cout << m_gameScore;
        std::cout << m_myTurn.getScoreThisTurn() << " turns!";
        std::cout << "\nThanks for playing PIG Dice!";
}