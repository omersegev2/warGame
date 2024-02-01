#include <iostream>
#include <fstream>
//#include "Game.hpp"
#include "Game.hpp"

int main() {
    // Initialize the main deck for the game
    Deck mainDeck;
    // Populate the deck from the file
    //problem
    mainDeck.populateDeckFromFile("Cards.txt");
    // mainDeck.print_cards();
    // Shuffle the main deck before starting
    //mainDeck.shuffle();
    // mainDeck.print_cards();

    //Create two players
    Player player1("Alice");
    Player player2("Bob");
    // Distribute cards to each player from the main deck 
    while (!mainDeck.isEmpty()) {
    //here there is a problem
        player1.receiveCard(mainDeck.draw());
        //std::cout <<"error"<<std::endl;
        if (!mainDeck.isEmpty()) {
            player2.receiveCard(mainDeck.draw());
        }
    }
    // player1.print_deck();
    // player2.print_deck();
    // mainDeck.print_cards();

    // // // Initialize the game with the two players
    Game warGame(player1,player2);
    
    // // //yuval said not necessary
    // // //warGame.start();

    // //Main game loop
    bool gameRunning = true;

    while (gameRunning) {
        // Play a round
        warGame.playRound();    //need to fix

        //Check for a winner
        int winner = warGame.checkWinner();
        if (winner != 0) {
            gameRunning = false;
            std::cout << "Player " << winner << " wins the game!" << std::endl;
            warGame.print_player();
        }
        
    }
    return 0;
}