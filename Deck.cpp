#include "Deck.hpp"

Deck::Deck(const Deck &other) : cards(nullptr), cardCount(other.cardCount)
{
    if (cardCount > 0)
    {
        cards = new Card[cardCount];
        for (int i = 0; i < cardCount; ++i)
        {
            cards[i] = other.cards[i];
        }
    }
}

Deck::~Deck()
{
    delete[] cards;
}

Deck &Deck::operator=(const Deck &other)
{
    if (this != &other)
    { // Check for self-assignment
        // Deallocate existing resources
        delete[] cards;
        // Copy cardCount
        cardCount = other.cardCount;

        if (other.cards != nullptr)
        {
            // Allocate new memory for cards and copy each Card object
            cards = new Card[cardCount];
            for (int i = 0; i < cardCount; ++i)
            {
                cards[i] = other.cards[i];
            }
        }
        else
        {
            cards = nullptr;
        }
    }
    return *this;
}

void Deck::shuffle()
{
    srand(static_cast<unsigned>(time(0)));
    for (int i = cardCount - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }
}

Card Deck::draw()
{
    // Check if the deck is empty
    if (isEmpty())
    {
        std::cout << "Deck is empty!" << std::endl;
        // Return a default card
        return Card();
    }
    // Decrement the card count
    --cardCount;
    // Get the top card from the deck
    Card topCard = cards[cardCount];
    // Resize the deck
    Card *temp = new Card[cardCount];
    for (int i = 0; i < cardCount; ++i)
    {
        temp[i] = cards[i];
    }
    if (this->cardCount > 0 && this->cards != nullptr)
        delete[] this->cards;
    cards = temp;
    // Return the top card
    return topCard;
}

void Deck::populateDeckFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    int flag = 0;
    while (getline(file, line))
    {
        int position = line.find(",");
        std::string newsuit = line.substr(0, position);
        std::string newrank = line.substr(position + 2);

        const std::string validrank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        for (int i = 0; i < 13; i++)
        {
            if (newrank == validrank[i])
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }

        Suit s = FindSuit(newsuit);

        // if ((flag == 1) && newsuit != "Empty")
        // {
        Card newcard = Card(s, newrank.c_str());
        this->Add_card(newcard);
        // }
    }
    file.close();
}

Suit Deck::FindSuit(std::string s)
{

    if ((strcmp(s.c_str(), "Hearts")) == 0)
    {
        return Hearts;
    }
    else if ((strcmp(s.c_str(), "Diamonds")) == 0)
    {
        return Diamonds;
    }
    else if ((strcmp(s.c_str(), "Spades")) == 0)
    {
        return Spades;
    }
    else if ((strcmp(s.c_str(), "Clubs")) == 0)
    {
        return Clubs;
    }
    return Unknown;
}

bool Deck::isEmpty()
{
    if (this->cardCount == 0)
        return true;
    return false;
}

void Deck::Add_card(Card &new_card)
{
    // std::cout << "problem in the Add card func" << std::endl;
    ++(this->cardCount);
    Card *temp = new Card[cardCount]; // Allocate memory for the new array

    if (temp == nullptr)
    {
        std::cout << "Memory Allocation failed" << std::endl;
        --(this->cardCount);
        return;
    }

    temp[0] = new_card;
    int j = 1;
    // Copy existing cards to the new array
    for (int i = 0; i < cardCount - 1; i++)
    {
        temp[j] = this->cards[i];
        ++j;
        //*this->cards[i] = NULL;
    }

    // Add the new card to the end of the array
    // temp[cardCount - 1] = new_card;

    // delete the old array if it exists
    if (this->cards != nullptr)
    {
        delete[] this->cards;
    }

    // Update the cards pointer to point to the new array
    this->cards = temp;
}

void Deck::print_cards()
{
    if (this->cardCount <= 0)
    {
        std::cout << "the Deck is empty" << std::endl;
    }
    for (int i = 0; i < cardCount; i++)
    {
        if (this->cards[i].GetRank() != nullptr)
        {
            std::cout << "Card: " << i << ": ";
            std::cout << this->cards[i].GetRank() << std::endl;
        }
    }
}
