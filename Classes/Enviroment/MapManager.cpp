#include "MapManager.h"
#include "TileFactory.h"
#include "TileNode.h"

USING_NS_CC;

MapManager::MapManager()
{
    tileFactory = std::make_unique<TileFactory>();
    auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
    tileSizeWidth = sampleTile->getContentSize().width;
    tileSizeHeight = sampleTile->getContentSize().height;
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(cocos2d::Vec2(-tileSizeWidth * 0, -tileSizeHeight * 15));
    createMap();
}

MapManager::~MapManager()
{
}

bool MapManager::init() {
    if (!Layer::init()) {
        return false;
    }

    return true;
}

void MapManager::createMap() {
    // screen 16 x 9
    createMapSymbol();
    height = mapSymbol.size();
    width = mapSymbol.size() == 0 ? 0 : mapSymbol.at(0).size();
    map = std::vector<std::vector<TileNode*>>();
    map.resize(height);
    for (int j = 0; j < height; j++) {
        map.at(j).resize(width);
    }
    auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            map.at(j).at(i) = tileFactory->getTileNode(mapSymbol.at(j).at(i), tileSizeWidth * i, tileSizeHeight * (height - j - 1));
            auto sprite = map.at(j).at(i);
            if (sprite != nullptr) {
                int layer = 1;
                if (mapSymbol.at(j).at(i) == '|' || mapSymbol.at(j).at(i) == '/') {
                    layer = 0;
                }
                this->addChild(sprite, layer);
            }
        }
    }
}

void MapManager::checkCollide(Player& player) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            map.at(j).at(i)->isCollide(player);
        }
    }
}

void MapManager::createMapSymbol() {
    mapSymbol = std::vector<std::vector<char>>();
    mapSymbol = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','^','^','^','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','S','.','.','.','.','.','.','#','#','#','#','#','#','#','#','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','#','.','.','.','.','.','#','.','#','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','}','.','.','.','.','.','.','.','.','.','+',']','.','.','.','.','.','.','#','#','#','^','^','^','^','^','^','^','#','.','.','.','.','.','.','|','.','.','.','.','.','.','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','>','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','>','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','>','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','$','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','}','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#','#','#','#','#','#','#','#','.','.','.','.','.','#','#','#','#','#','.','.','.','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','/','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#','^','^','^','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#','.','.','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','#','.','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','+',']','.','.','.','^','^','^','^','^','}','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };
}