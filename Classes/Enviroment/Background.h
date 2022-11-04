#pragma once

#include "cocos2d.h"
#include "TileNode.h"

class Background: public TileNode {
public:
	Background(float x, float y, std::string nameObject);
	~Background();
	void Background::destroy();
	virtual void doInteract(Player* player);
private:
	bool canDestroy;
	bool coverKey;
	bool isKey;
};