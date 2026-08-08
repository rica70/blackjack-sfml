#include "Hand.hpp"
// default constructor - starts empty
Hand::Hand()
{
}
// appends card to the back of the hand
void Hand::AddCard(Card C)
{
    cards.push_back(C);
}
// calculates and returns our hands value
int Hand::GetHandValue() const
{
    int runningSum = 0;
    int Aces = 0;
    for (auto &c : cards)
    {
        if (c.getRankString() == "A")
            Aces++;
        runningSum += c.getValue();
    }

    if (runningSum > 21)
    {
        while (Aces > 0 && runningSum > 21)
        {
            runningSum -= 10;
            Aces--;
        }
    }
    return runningSum;
}
// returns true if we are hand is eligible to split
bool Hand::CheckSplit()
{
    if (cards.size() == 2)
    {
        if (cards[0].getValue() == cards[1].getValue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
// removes the last card out
Card Hand::removeCard()
{
    Card temp = cards.back();
    cards.pop_back();
    return temp;
}
// overload += to add a card directly to a hand
void operator+=(Hand &H, Card C)
{
    H.cards.push_back(C);
}
void Hand::PrintCardByIndex(int i)
{
    cout << "The " << cards[i].getRankString() << " of " << cards[i].getSuit() << ", Value: " << ((cards[i].getValue() == 11) ? "1-11" : to_string(cards[i].getValue())) << endl;
}
int Hand::getHandSize() const
{
    int size = 0;
    for (auto &c : cards)
    {
        size++;
    }
    return size;
}
int Hand::GetHandValueIndex(int i) const
{
    return cards[i].getValue();
}
// overload << to print each card in the output stream
ostream &operator<<(ostream &out, Hand &H)
{
    for (auto &c : H.cards)
        out << "The " << c.getRankString() << " of " << c.getSuit() << ", Value: " << ((c.getValue() == 11) ? "1-11" : to_string(c.getValue())) << endl;
    return out;
}

string Hand::getCardPathname(int i) const
{
    return cards[i].getPathname();
}

