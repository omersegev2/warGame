#include "Player.hpp"

Player::Player(const char *playerName)
{
    name = strdup(playerName);
}

Player::Player(const Player &other) : hand(other.hand)
{
    name = strdup(other.name);
}

void Player::setName(char *newName)
{
    delete[] name;
    if (newName != nullptr)
    {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    else
    {
        name = nullptr;
    }
}

// void Player:: Add_temp_deck(Deck temp_deck){
//     while (temp_deck.getCardCount() != 0)
//     {
//         Card card = temp_deck.Get_card();
//         this->hand.Add_card(card);
//         temp_deck.Delete_card();
//     }
// }

// Deck& Player::getHand(){
//     return hand;
// }

Card Player::draw()
{
    // Check if the hand is empty
    // if (hand.isEmpty()) {
    //     // Return a default card
    //     std::cout << "Hand is empty!" << std::endl;
    //     return Card();
    // }
    // Draw a card from the hand
    return hand.draw();
}

void Player::Add_temp_deck(Deck temp_deck)
{
    while (!temp_deck.isEmpty())
    {
        Card card = temp_deck.draw();
        this->hand.Add_card(card);
    }
}

int Player::CheckHand()
{
    if (hand.isEmpty())
    {
        return 1;
    }
    return 0;
}