#pragma once
#include "Item.h"
#include "../Player/Player.h"
#include "cocos2d.h"

class ItemManager {
public:
	ItemManager();
	~ItemManager();
	void AddItem(const Item& i_item);
	void RemoveItem(const Item& i_item);
	

	void ApplyEffect(Player& i_player);
	Item GenerateItem();

private:
	std::vector<Item> m_itemList;
};