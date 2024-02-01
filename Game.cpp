#include "Game.hpp"

void Game::playRound()
{
    // Check if any player has run out of cards
    if (player1.getCardCount_() == 0 || player2.getCardCount_() == 0)
    {
        cout << "game is over" << endl;
        return; // Game is over
    }
    // Each player plays a card
    Card card1 = player1.draw();
    Card card2 = player2.draw();
    if (card1.GetRank() == nullptr || card2.GetRank() == nullptr)
    {
        cout << "Default card constructor" << endl;
        return;
    }
    std::cout << "Player 1 plays: " << card1.GetRank() << std::endl;
    std::cout << "Player 2 plays: " << card2.GetRank() << std::endl;

    // Compare the ranks of the cards
    int rank1 = new_atoi(card1.GetRank());
    int rank2 = new_atoi(card2.GetRank());

    if (rank1 > rank2)
    {
        // Player 1 wins the round
        std::cout << "player 1 count: " << player1.getCardCount_() << std::endl;
        std::cout << "player 2 count: " << player2.getCardCount_() << std::endl;
        std::cout << "Player 1 wins the round!" << std::endl;
        player1.receiveCard(card1);
        player1.receiveCard(card2);
    }
    else if (rank1 < rank2)
    {
        // Player 2 wins the round
        std::cout << "player 1 count: " << player1.getCardCount_() << std::endl;
        std::cout << "player 2 count: " << player2.getCardCount_() << std::endl;
        std::cout << "Player 2 wins the round!" << std::endl;
        player2.receiveCard(card1);
        player2.receiveCard(card2);
    }
    else if (rank1 = rank2)
    {
        // War
        std::cout << "player 1 count: " << player1.getCardCount_() << std::endl;
        std::cout << "player 2 count: " << player2.getCardCount_() << std::endl;
        std::cout << "War!" << std::endl;
        // Add the cards to a temporary deck for comparison
        Deck warDeck;
        warDeck.Add_card(card1);
        warDeck.Add_card(card2);
        bool round = true;
        while (round)
        {
            // std::cout << "player 1 count: " << player1.getCardCount_() << std::endl;
            // std::cout << "player 2 count: " << player2.getCardCount_() << std::endl;
            if (player1.getCardCount_() > 3 || player2.getCardCount_() > 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    Card faceDown1 = player1.draw();
                    Card faceDown2 = player2.draw();
                    warDeck.Add_card(faceDown1);
                    warDeck.Add_card(faceDown2);
                }
                Card faceUp1 = player1.draw();
                Card faceUp2 = player2.draw();

                warDeck.Add_card(faceUp1);
                warDeck.Add_card(faceUp2);

                int warRank1 = new_atoi(faceUp1.GetRank());
                int warRank2 = new_atoi(faceUp2.GetRank());
                if (warRank1 > warRank2)
                {
                    // Player 1 wins the war
                    std::cout << "Player 1 wins the war!" << std::endl;
                    while (!warDeck.isEmpty())
                    {
                        player1.receiveCard(warDeck.draw());
                    }
                    break;
                }
                else if (warRank1 < warRank2)
                {
                    // Player 2 wins the war
                    std::cout << "Player 2 wins the war!" << std::endl;
                    while (!warDeck.isEmpty())
                    {
                        player2.receiveCard(warDeck.draw());
                    }
                    break;
                }
                else
                {
                    // Another war
                    std::cout << "Another war!" << std::endl;
                }
            }
            else
            {
                cout << "there is no enough cards" << endl;
                
                int num = checkWinnerWhenThereIsNotEnoughCards(player1, player2);
                if (num == 1)
                {
                    while (!warDeck.isEmpty())
                    {
                        player1.receiveCard(warDeck.draw());
                    }
                    this->player2.SetCardCount();
                }
                else if (num == 2)
                {
                    while (!warDeck.isEmpty())
                    {
                        player2.receiveCard(warDeck.draw());
                    }
                    this->player1.SetCardCount();
                }
                round = false;
            }
            // Each player places one card face down
            // Each player places one card face up

            // std::cout << "Player 1 plays: " << faceUp1.GetRank() << std::endl;
            // std::cout << "Player 2 plays: " << faceUp2.GetRank() << std::endl;
        }
    }

    return;
}

int Game::checkWinner()
{
    if (this->player1.getCardCount_() != 0 && this->player2.getCardCount_() != 0)
    {
        return 0;
    }
    if (this->player1.getCardCount_() == 0)
    {
        // player 2 is the winner
        return 2;
    }
    else if (this->player2.getCardCount_() == 0)
    {
        // player 1 is the winner
        return 1;
    }
}

int Game::new_atoi(const char *name_card)
{
    if (std::strcmp(name_card, "Jack") == 0)
        return 11;
    else if (std::strcmp(name_card, "Queen") == 0)
        return 12;
    else if (std::strcmp(name_card, "King") == 0)
        return 13;
    else if (std::strcmp(name_card, "Ace") == 0)
        return 1;
    else
        return std::atoi(name_card);
}

int Game::checkWinnerWhenThereIsNotEnoughCards(Player player1, Player player2)
{
    int num1 = player1.getCardCount_();
    int num2 = player2.getCardCount_();
    if (num1 > num2)
    {
        // player 1 is winner
        return 1;
    }
    else if (num2 > num1)
    {
        return 2;
    }
}

void Game::print_player()
{
    cout << this->player1.getName() << endl;
    this->player1.print_deck(); 
    cout << this->player2.getName() << endl;
    this->player2.print_deck();
}