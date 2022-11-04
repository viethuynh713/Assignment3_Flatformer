#pragma once

#include "cocos2d.h"
#include "TileFactory.h"
#include "TileNode.h"

class MapManager: public cocos2d::Layer {
public:
	MapManager();
	~MapManager();
	virtual bool init();
	bool checkCollide(Player& player);
	void move(cocos2d::Vec2 dir);
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