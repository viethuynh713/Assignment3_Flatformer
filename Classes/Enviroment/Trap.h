#pragma once

#include "cocos2d.h"
#include "TileNode.h"
#include "Player/Player.h"

class Trap : public TileNode {
public:
	Trap(float x, float y);
	Trap(float x, float y, int angle);
	~Trap();
	virtual void doInteract(Player* player);
private:
	int damage;
};