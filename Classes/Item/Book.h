#pragma once

#include "Item.h"
#include "cocos2d.h"

class Book : public Item{
public:
	Book();
	~Book();
	void applyEffect(const Player& i_player) override;

	void AddSkill(Player& i_player);
private:
	cocos2d::Vec2 m_position;
	std::string m_itemId;
	RECT m_hitBox;
};