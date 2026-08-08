//
//  Card.hpp
//  final proj test
//
//  Created by Ricardo Acosta on 4/27/26.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

// card class - stores the properties of one playing card
class Card
{
private:
    int value;
    string suit;
    string rankString;
public:
    Card();
    Card(int, string, string);
    int getValue() const; // Returns the BlackJack Value of the card (1-11)
    string getSuit() const; // returns the suit ( hearts, space, ect)
    string getRankString() const; // returns the name (Ace, king, ect)
    string getPathname() const; // returns pathname to image (Sprites/suit_rank.png)
    
    
    
    
};
