#pragma once

#include "../Player/Player.h"
#include "cocos2d.h"

class Item: public cocos2d::Sprite {
public:
	Item();
	~Item();
	virtual void applyEffect(const Player& i_player);
};