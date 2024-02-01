#include "Player.hpp"

class Game {
private:
    Player player1;
    Player player2;

public:
    // Constructor
    Game(char *p1, char *p2) : player1(p1), player2(p2) {}
    //constructor
    Game(Player &p1, Player &p2):player1(p1),player2(p2){};
    // Copy constructor
    Game(const Game &other) : player1(other.player1), player2(other.player2){}
    // Destructor
    ~Game() {}
    // Function to play a round
    void playRound();
    // function to start the game 
    //void start();
    //in my game the winner is the player who dont have cards.
    int checkWinner();

    int new_atoi(const char *name_card);

    //int WhoWinRound(Card card1,Card card2);

    int checkWinnerWhenThereIsNotEnoughCards(Player player1,Player player2);
    void print_player();
};
