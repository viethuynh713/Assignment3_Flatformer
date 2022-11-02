#pragma once

#include "cocos2d.h"
#include "TileNode.h"

class Door : public TileNode {
public:
	Door(float x, float y, int p_nKeyNeed);
	~Door();
	virtual void doInteract(Player& player);
	void open();
private:
	int nKeyNeed;
	bool isOpened;
};