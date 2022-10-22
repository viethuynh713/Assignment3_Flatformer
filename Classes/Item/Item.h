#pragma once
#include "IItem.h"
#include "ItemEffect.h"
#include "cocos2d.h"

class Item : IItem {
public:
	void applyEffect() const override;
private:
	Item();
	~Item();
	
	std::pair<float, float> m_position;
	std::string m_itemId;
	std::unique_ptr<ItemEffect> m_effect;
	RECT m_hitBox;
};