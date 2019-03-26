/*
 * Game.h
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <string>

#include "Player.h"
#include "Deck.h"
#include "House.h"

class Game
{
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    //plays the game of blackjack
    void Play();
    void WinPercentage();
    static int winningValue;
    static void setWinningValue();
    int numGamesPlayed;

private:
    std::vector<Player> m_Players;

    Deck m_Deck;
    House m_House;

};

#endif /* GAME_H_ */
