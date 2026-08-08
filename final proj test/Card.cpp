//
//  Card.cpp
//  final proj test
//
//  Created by Ricardo Acosta on 4/27/26.
//

#include "Card.hpp"
// default constructor - initializes card to nothing
Card::Card()
{
    value = 0;
    suit = "none";
}
//constructor to initialize card
Card::Card(int v, string s, string rs)
{
    value = v;
    suit = s;
    rankString = rs;
}
//getters
int Card::getValue() const
{
    return value;
}

string Card::getSuit() const
{
    return suit;
}

string Card::getRankString() const
{
    return rankString;
}

string Card::getPathname() const
{
    return  "Sprites/" + getSuit() + "_" + getRankString() + ".png";

}
