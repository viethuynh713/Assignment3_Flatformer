#pragma once

#include "cocos2d.h"
#include "TileNode.h"

class Ground : public TileNode {
public:
	Ground(float x, float y);
	~Ground();
};