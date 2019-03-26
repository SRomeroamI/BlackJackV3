/*
 * Player.h
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");

    int numPlayerWins;

    virtual ~Player();

    //returns whether or not the player wants another hit
    virtual bool IsHitting() const;

    //announces that the player wins
    void Win();

    //announces that the player loses
    void Lose() const;

    //announces that the player pushes
    void Push() const;
};


#endif /* PLAYER_H_ */
