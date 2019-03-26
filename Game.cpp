/*
 * Game.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#include <ctime>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>

#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(const std::vector<std::string>& names)
{
	numGamesPlayed = 0;
    //create a vector of players from a vector of names
    std::vector<std::string>::const_iterator pName;

    for (pName = names.begin(); pName != names.end(); ++pName)
	{
        m_Players.push_back(Player(*pName));
	}

	//seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::setWinningValue() {
	std::srand(std::time(0));
	Game::winningValue = std::rand() % 6 + 16;
}

void Game::Play()
{
	std::cout << "\nYou need to get to " << Game::winningValue << " to win the game.  Good Luck!\n" << std::endl;

    //deal initial 2 cards to everyone
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
            m_Deck.Deal(*pPlayer);
		}
        m_Deck.Deal(m_House);
    }

    //hide house's first card
    m_House.FlipFirstCard();

    //display everyone's hand
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        std::cout << *pPlayer << std::endl;
	}
    std::cout << m_House << std::endl;

    //deal additional cards to players
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        m_Deck.AdditionalCards(*pPlayer);
	}

    //reveal house's first card
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    //deal additional cards to house
    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        //everyone still playing wins
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
            if ( !(pPlayer->IsBusted()) )
			{
                pPlayer->Win();
			}
		}
    }
    else
    {
         //compare each player still playing to house
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if ( !(pPlayer->IsBusted()) )
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    numGamesPlayed ++;

    //remove everyone's cards
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        pPlayer->Clear();
	}
    m_House.Clear();
}

/*
 * Calculates the win percentage of all the players and the House.
 * Prints out the result.  Returns void.
 */
void Game::WinPercentage() {

	double winPercent = 0.0f;
    std::vector<Player>::iterator pPlayer;

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
    	winPercent = (double) pPlayer->numPlayerWins/ (double) numGamesPlayed;
    	std::cout << pPlayer->getName() << " has won " << winPercent << " percent of the games." << std::endl;
	}
}


//	Need to define the static

int Game::winningValue = 0;

int main()
{

    std::cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "How many players? (1 - 7): ";
        std::cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }

    //the game loop

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
    	Game::setWinningValue();
        aGame.Play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    }

    aGame.WinPercentage();

    return 0;
}
