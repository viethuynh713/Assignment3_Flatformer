#pragma once

#include "Item.h"
#include "cocos2d.h"

class AddHP : public Item{
public:
	AddHP();
	~AddHP();
	void applyEffect(Player& i_player) override;

	void HPChange(Player& i_player);
};