#pragma once

#include "Item.h"
#include "cocos2d.h"

class Coin : public Item{
public:
	Coin();
	~Coin();
	void applyEffect(const Player& i_player) override;
};