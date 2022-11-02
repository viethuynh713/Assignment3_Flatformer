#pragma once

#include "Item.h"
#include "cocos2d.h"

class Key : public Item {
public:
	Key();
	~Key();
	void applyEffect(Player& i_player) override;
private:
	cocos2d::Vec2 m_position;
	std::string m_itemId;
	RECT m_hitBox;
};