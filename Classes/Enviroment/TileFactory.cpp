#include "TileFactory.h"
#include "TileNode.h"
#include "Background.h"
#include "Ground.h"
#include "Trap.h"
#include "Chest.h"
#include "Door.h"
#include "Item/Key.h"
#include "Item/Star.h"
#include "Item/Coin.h"

USING_NS_CC;

TileFactory::TileFactory()
{
    
}

TileFactory::~TileFactory()
{
}

TileNode* TileFactory::getTileNode(char c, float x, float y) {
    TileNode* tile = nullptr;
    if (c == '#') {
        tile = new Ground(x, y);
    }
    else if (c == '.' || c == 'S') {
        tile = nullptr;
    }
    else if (c == '+') {
        tile = new Background(x, y, "bush");
    }
    else if (c == ']') {
        tile = new Background(x, y, "key");
    }
    else if (c == '|' || c == '/') {
        int nKey = 2;
        if (c == '/') {
            nKey = 3;
        }
        tile = new Door(x, y, nKey);
    }
    else if (c == '^') {
        tile = new Trap(x, y);
    }
    else if (c == '>') {
        tile = new Trap(x, y, 90);
    }
    else if (c == '*') {
        tile = new Coin(x, y);
    }
    else if (c == '$' || c == '}') {
        auto rewardList = std::vector<Item*>();
        if (c == '}') {
            rewardList.push_back(new Key());
        }
        rewardList.push_back(new Star());
        tile = new Chest(x, y, rewardList);
    }
    return tile;
}