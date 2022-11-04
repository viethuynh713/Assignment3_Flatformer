#pragma once

#include "Item.h"
#include "cocos2d.h"

class Book : public Item{
public:
	Book();
	~Book();
	void applyEffect(Player* i_player) override;

	void AddSkill(Player* i_player);
};