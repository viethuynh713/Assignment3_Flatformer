#pragma once

#include "Item.h"
#include "cocos2d.h"

class AddHP : public Item{
public:
	AddHP();
	~AddHP();
	void applyEffect(const Player& i_player) override;

	int HPChange();
private:
	cocos2d::Vec2 m_position;
	std::string m_itemId;
	RECT m_hitBox;
};