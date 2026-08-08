//
//  Deck.cpp
//  final proj test
//
//  Created by Ricardo Acosta on 5/4/26.
//

#include "Deck.hpp"

// builds a standard 52-card deck
Deck::Deck()
{
    // blackjack values
    string suits[] = {"hearts", "diamonds", "clubs", "spades"};
    int values[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
    string rankStrings[] = {"A","2","3","4","5","6","7","8","9","10","J", "Q","K"};
    // looping though each suit and create a 13 cards per suit
    for(auto& s : suits){
        for (int i = 0; i < 13; i++)
        {
            cards.push_back(Card(values[i], s, rankStrings[i]));
        }
    }
}

// removes and returns the top card (back of our vector) from the deck
Card Deck::dealCard()
{
    Card temp = cards.back();
    cards.pop_back();
    return temp;
    
    
}

//prints every card in deck for testing
void Deck::print()
{
    for(auto& c : cards)
    {
        cout << c.getValue() << " " << c.getSuit() << " " << c.getRankString() << endl;
    }
}

// shuffles the deck using a time based seed which is set to the current time
// so its different every run.
void Deck::shuf()
{
    unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

string Deck::cardPathname (int i)
{
    return cards[i].getPathname();
}
