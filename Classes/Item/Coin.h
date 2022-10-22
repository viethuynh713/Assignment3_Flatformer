#pragma once

#include "Item.h"
#include "cocos2d.h"

class Coin : public Item{
public:
	Coin();
	~Coin();
	void applyEffect(const Player& i_player) override;
private:
	cocos2d::Vec2 m_position;
	std::string m_itemId;
	RECT m_hitBox;
};