#pragma once

#include "cocos2d.h"
#include "Player/Player.h"

class TileNode: public cocos2d::Sprite {
public:
	TileNode();
	TileNode(int x, int y);
	~TileNode();
	bool isCollide(Player& player);
	virtual void doInteract(Player& player);
};