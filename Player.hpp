#include "Deck.hpp"

class Player {
private:
    char* name;
    Deck hand;

public:
    // Constructor
    Player(const char* playerName);
    // Copy Constructor
    Player(const Player& other);
    // Destructor
    ~Player() {delete[] name;}
    // Setter for name
    void setName(char* newName);
    // Getter for name
    const char* getName()const{return name;}
    // Setter for hand
    void setHand(const Deck& newHand){hand = newHand;}
    // Getter for hand
    const Deck& getHand()const {return hand;}
    // Receive a card and add it to the hand
    void receiveCard(Card c){return this->hand.Add_card(c);}
    //
    int getCardCount_ (){return this->hand.getCardCount();}
    //
    void Add_temp_deck(Deck temp_deck);
    //Card GetCard(){return this->hand.Get_card();}
    void print_deck(){
        std::cout << "player " << this->getName()<<":"<<std::endl;
        std::cout <<"***********************************"<<std::endl;
        return this->hand.print_cards();}
    //Deck& getHand();
    Card draw();
    int CheckHand();
    void SetCardCount(){this->hand.SetCardCount();}
};



