/*
 * Card.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#include <ostream>
#include <string>
#include "Card.h"

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    //if a card is face down, its value is 0
    int value = 0;
    if (m_IsFaceUp)
    {
        //value is number showing on card
        value = m_Rank;
        //value is 10 for face cards
        if (value > 10)
		{
            value = 10;
		}
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

//overloads << operator so Card object can be sent to cout
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = {"0", "Ace of ", "2 of ", "3 of ", "4 of ", "5 of ", "6 of ", "7 of ", "8 of ", "9 of ",
                            "10 of ", "Jack of ", "Queen of ", "King of "};
    const std::string SUITS[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}


