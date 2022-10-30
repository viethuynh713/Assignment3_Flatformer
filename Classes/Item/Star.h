#pragma once

#include "Item.h"
#include "cocos2d.h"

class Star : public Item{
public:
	Star();
	~Star();
	void applyEffect(const Player& i_player) override;

	int LivesChange(Player& i_player);
	float SpeedChange(Player& i_player);
private:
	cocos2d::Vec2 m_position;
	std::string m_itemId;
	RECT m_hitBox;
};