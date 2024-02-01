#include "Card.hpp"

void Card::SetName(char *name)
    {
        this->rank = new char[strlen(name) + 1];
        if (this->rank == NULL)
        {
            std::cout << "Memory Allocation Fail" << std::endl;
        }
        strcpy(this->rank, name);
    }

Card &Card::operator=(const Card& other){
    if (this == &other)
        return *this;       //check for self assignment
    this->suit = other.suit;
    if (rank != nullptr)
        delete [] this->rank;
    rank = new char[strlen(other.rank)+1];
    strcpy (this->rank,other.rank);
    return *this;
}
