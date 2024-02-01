#include "Card.hpp"

class Deck {
private:
    Card* cards;
    int cardCount;

public:
    // Default Constructor
    Deck():cards(nullptr), cardCount(0) {}
    // Destructor
    ~Deck();
    // Copy Constructor
    Deck(const Deck& other);
    // Shuffle the cards in the deck
    void shuffle();
    // Draw a card from the deck
    Card draw();
    //
    Suit FindSuit(std::string s);
    // Populate the deck from a file
    void populateDeckFromFile(const std::string& filename);
    //
    bool isEmpty();
    //
    void Add_card(Card &new_card);
    //
    int getCardCount(){return cardCount;}
    //
    void print_cards();
    //
    Deck& operator=(const Deck& other);
    void SetCardCount(){this->cardCount = 0;}
};

