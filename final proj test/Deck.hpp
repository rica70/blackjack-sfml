//
//  deck.hpp
//  final proj
//
//  Created by Ricardo Acosta on 4/27/26.
//
#pragma once
#include "Card.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


using namespace std;

// Represents a standard 52-card playing deck.
// containts a collection of card objects.

//Deck class - build and manages a 52 - Card deck
class Deck{
private:
    vector<Card> cards; // Composition of Card objects making up the deck
    
public:
    Deck();
    Card dealCard(); // removes and returns the top card of the deck
    void print(); // Prints all remaing card in the deck (testing)
    void shuf(); // shuffles the deck in random order
    string cardPathname (int i);
    
};
