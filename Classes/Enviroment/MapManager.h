#pragma once

#include "cocos2d.h"
#include "TileFactory.h"
#include "TileNode.h"

class MapManager: public cocos2d::Layer {
public:
	MapManager();
	~MapManager();
	virtual bool init();
	void checkCollide(Player& player);
private:
	std::unique_ptr<TileFactory> tileFactory;
	std::vector<std::vector<char>> mapSymbol;
	std::vector<std::vector<TileNode*>> map;
	int width;
	int height;
	int tileSizeWidth;
	int tileSizeHeight;
	void createMap();
	void createMapSymbol();
};