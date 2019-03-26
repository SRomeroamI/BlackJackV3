/*
 * GenericPlayer.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#include <string>
#include <iostream>
#include "GenericPlayer.h"
#include "Card.h"
#include "Game.h"

GenericPlayer::GenericPlayer(const std::string& name):
    m_Name(name)
{
}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > Game::winningValue);
}

void GenericPlayer::Bust() const
{
    std::cout << m_Name << " busts.\n";
}

std::string GenericPlayer::getName() {
	return m_Name;
}

//overloads << operator so a GenericPlayer object can be sent to cout
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

   std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }


        if (aGenericPlayer.GetTotal() != 0)
		{
            std::cout << "Total Points: " << aGenericPlayer.GetTotal();
		}
    }
    else
    {
        os << "<empty>";
    }

    return os;
}


