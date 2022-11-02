#pragma once

#include "Item.h"
#include "../Player/Player.h"
#include "cocos2d.h"

class ItemManager: public cocos2d::Layer {
public:
	ItemManager();
	~ItemManager();
	void AddItem(Item* i_item);
	void RemoveItem(Item i_item);
	

	void ApplyEffect(Player& i_player);
	Item* GenerateItem();

private:
	std::vector<Item*> m_itemList;
};