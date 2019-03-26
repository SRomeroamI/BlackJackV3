/*
 * GenericPlayer.h
 *
 *  Created on: Feb 25, 2019
 *      Author: SRomero
 */

#ifndef GENERICPLAYER_H_
#define GENERICPLAYER_H_

#include <string>
#include <ostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");

    virtual ~GenericPlayer();

    //indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;

    //announces that the generic player busts
    void Bust() const;

    std::string getName();

protected:
    std::string m_Name;

};

#endif /* GENERICPLAYER_H_ */
