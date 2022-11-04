#pragma once

#include "cocos2d.h"
#include "TileNode.h"
#include "Item/Item.h"
#include "Player/Player.h"

class Chest : public TileNode {
public:
	Chest(float x, float y, std::vector<Item*> p_rewardList);
	~Chest();
	virtual void doInteract(Player* player);
private:
	std::vector<Item*> rewardList;
	bool isClosing;
};