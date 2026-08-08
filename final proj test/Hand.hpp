#pragma once
#include "Card.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Represents both the Player's and Dealer's hand.
// containts a collection of card objects.
//Hand class - creates and contains a person's cards
class Hand{
// overloaded operators
friend void operator+=(Hand &H, Card C);
friend ostream& operator<<(ostream &out, Hand &H);
private:
    vector<Card> cards; // Composition of Card objects in the Hand
public:
    // Defualt constructer
    Hand();
    // Setters
    void AddCard(Card C); // used to add cards to the hands
    // Getters
    int GetHandValue() const; // gets the value of our hands
    bool CheckSplit(); //checks if we are able to split
    Card removeCard(); // removes the card if when called
    void PrintCardByIndex(int);
    int getHandSize() const; // returns a int of size 
    int GetHandValueIndex(int i) const; // gets the value of a card by the index
    string getCardPathname(int i) const;
    
};


