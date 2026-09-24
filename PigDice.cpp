/*#include <iostream>
#include <ctime>
#include <cstdlib>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

//void addScore(GameState &gs) {
    //gs.game_score += 10;


void take_turn(GameState &g);
void play_game(GameState &g);
void roll(GameState &g);
void hold(GameState &g);
void display_rules();


    int main() {
    GameState my_game; // instantiate a GameState object
    //addScore (my_game);
    //my_game.game_score;
    std::cout <<"Game score is: " << my_game.game_score << std::endl;
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void display_rules() {
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


void play_game(GameState &g) {
        while (!g.game_over) {
            take_turn(g);
            g.game_score +=g.score_this_turn;
            if (g.game_score >= 20) {
                g.game_over = true;
            }
            else {
                g.turn_over = false;
                g.score_this_turn = 0;
            }
    }
        std::cout << "\n\nYou finished with a final score of ";
        std::cout << g.game_score;
        std::cout << " in " << g.turn_count << " turns!.";
        std::cout << "\nThanks for playing PIG DICE!";
}
void take_turn(GameState &g) {
    g.turn_count++;
        std::cout << "\nTURN " << g.turn_count;
        std::cout << " - Game Score:" <<g.game_score;
        while (!g.turn_over) {
            std::cout << "\nroll or hold? (r/h): ";
            std::cin >> g.choice;
            if (g.choice == 'r') {
                roll(g);
            }
            else if (g.choice == 'h') {
                hold(g);
            }
             else {
                std::cout << "Invalid choice!";
                }
            }
                std::cout << "score banked this turn:" << g.score_this_turn;


        }


void roll(GameState &g) {
        srand(time(NULL));
        int die = rand() % 6 + 1;
        std::cout << "DIE:" << die;
        if (die == 1) {
            std::cout << "\nTurn Over. No Score.\n";
            g.score_this_turn = 0;
            g.turn_over = true;
        }
        else {
            g.score_this_turn+=die;
            std::cout << " - Running score this turn:" << g.score_this_turn;
        }
    }

void hold(GameState &g) {
    g.turn_over = true;
    }*/

#include <iostream>
#include <random>

// Die class
class Die {
private:
    int dieValue;
    int numOfSides;

public:
    //  default Constructor
    Die() {
        dieValue = 1;
        numOfSides = 6;
    }
    // setter for die value
    void setDieValue(int value) {
        dieValue = value;
    }
    // getter for die value
    int getDieValue() {
        return dieValue;
    }
    // setter for sides
    void setNumOfSides(int Sides) {
        if (Sides == 4 || Sides == 6 || Sides == 8) {
            numOfSides = Sides;
        }
    }
 // getter for sides
    int getNumOfSides() {
        return numOfSides;
    }

    void roll() {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> randomNumber(1, numOfSides);

        dieValue = randomNumber(gen);
    }
};


struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void take_turn(GameState &g, Die &d);
void play_game(GameState &g, Die &d);
void roll(GameState &g, Die &d);
void hold(GameState &g);
void display_rules();


int main() {
    GameState my_game;
    Die my_die;

    std::cout << "Game score is: "
              << my_game.game_score << std::endl;

    display_rules();

    play_game(my_game, my_die);

    return 0;
}


void display_rules() {
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


void play_game(GameState &g, Die &d) {

    while (!g.game_over) {
        take_turn(g, d);

        g.game_score += g.score_this_turn;

        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }

    std::cout << "\n\nYou finished with a final score of ";
    std::cout << g.game_score;
    std::cout << " in " << g.turn_count << " turns!.";
    std::cout << "\nThanks for playing PIG DICE!";
}


void take_turn(GameState &g, Die &d) {

    g.turn_count++;

    std::cout << "\nTURN " << g.turn_count;
    std::cout << " - Game Score: " << g.game_score;

    while (!g.turn_over) {

        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> g.choice;

        if (g.choice == 'r') {
            roll(g, d);
        }
        else if (g.choice == 'h') {
            hold(g);
        }
        else {
            std::cout << "Invalid choice!";
        }
    }

    std::cout << "score banked this turn: "
              << g.score_this_turn;
}


void roll(GameState &g, Die &d) {

    d.roll();

    int die = d.getDieValue();

    std::cout << "DIE: " << die;

    if (die == 1) {
        std::cout << "\nTurn Over. No Score.\n";

        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn += die;

        std::cout << " - Running score this turn: "
                  << g.score_this_turn;
    }
}


void hold(GameState &g) {
    g.turn_over = true;
}

