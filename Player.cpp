/*
 * Player.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#include <string>
#include <iostream>
#include "Player.h"

Player::Player(const std::string& name) :
	GenericPlayer(name)
{
	numPlayerWins = 0;
}

Player::~Player()
{}

bool Player::IsHitting() const
{
    std::cout << m_Name << ", do you want another card? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win()
{
	numPlayerWins++;

    std::cout << m_Name <<  " wins.\n";
}

void Player::Lose() const
{
    std::cout << m_Name <<  " loses.\n";
}

void Player::Push() const
{
    std::cout << m_Name <<  " pushes.\n";
}

