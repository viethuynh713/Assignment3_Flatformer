#pragma once

#include "../Player/Player.h"
#include "cocos2d.h"

class Item: public cocos2d::Sprite {
public:
	Item();
	~Item();
	virtual void applyEffect(const Player& i_player);
	friend bool operator==(Item const& i_item, Item const& o_item);
private:
	int m_id;
	cocos2d::Vec2 m_position;
	RECT m_rect;
};