#pragma once

#include "Item.h"
#include "cocos2d.h"

class Star : public Item{
public:
	Star();
	~Star();
	void applyEffect(Player* i_player) override;

	void StarChange(Player* i_player);
	void LivesChange(Player* i_player);
	void SpeedChange(Player* i_player);
};