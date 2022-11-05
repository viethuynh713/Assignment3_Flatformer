#pragma once

#include "Item.h"
#include "cocos2d.h"
#include "Enviroment/TileNode.h"

class Coin : public TileNode{
public:
	Coin();
	Coin(float x, float y);
	~Coin();
	void doInteract(Player* i_player) override;
private:
	bool canCollect;
};