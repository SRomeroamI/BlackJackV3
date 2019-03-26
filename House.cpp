/*
 * House.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#include <string>
#include <iostream>
#include "House.h"
#include "Card.h"

House::House(const std::string& name):
    GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
	{
        m_Cards[0]->Flip();
	}
    else
	{
		std::cout << "No card to flip!\n";
	}
}

