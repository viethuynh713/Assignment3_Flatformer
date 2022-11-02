#pragma once

#include "cocos2d.h"
#include "TileNode.h"

class TileFactory {
public:
	TileFactory();
	~TileFactory();
	TileNode* getTileNode(char c, float x, float y);
};