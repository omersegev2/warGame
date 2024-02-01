#include <iostream>
#include <cstring>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
#include <fstream>  // For file operations
#include <string>
#include <sstream>

using namespace std;
enum Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
    Unknown
};

class Card
{
private:
    Suit suit;
    char *rank;

public:
    // Default Constructor
    Card() : suit(Unknown)
    {
       rank = nullptr;
    }
    // Card(){};
    // Parameterized Constructor
    Card(Suit cardSuit, const char *cardRank) : suit(cardSuit)
    {
        this->rank = new char[strlen(cardRank) + 1];
        if (this->rank == NULL)
        {
            std::cout << "Memory Allocation Fail" << std::endl;
        }
        strcpy(rank, cardRank);
    }
    // Copy Constructor
    Card(const Card &other) : suit(other.suit)
    {
        this->rank = new char[strlen(other.rank) + 1];
        strcpy(rank, other.rank);
    }
    // Destructor
    ~Card()
    {
        delete[] rank;
    }
    const char *GetRank() { return rank; } //?

    void SetName(char *name);

    void SetSuit(Suit suit) {this->suit = suit;}

    Card &operator=(const Card &other);
};
