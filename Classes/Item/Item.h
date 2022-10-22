#pragma once
#include "../Player/Player.h"
#include "cocos2d.h"

class Item{
public:
	Item();
	~Item();
	virtual void applyEffect(const Player& i_player);
};