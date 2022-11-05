#include "Coin.h"
Coin::Coin()
{
	Item();
	this->initWithFile("coins/coin_01.png");
	canCollect = true;
}

Coin::Coin(float x, float y) {
	Item();
	this->initWithFile("coins/coin_01.png");
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(x, y);
	canCollect = true;
}

Coin::~Coin()
{
}

void Coin::doInteract(Player* i_player)
{
	if (canCollect) {
		i_player->addCoin();
		this->removeFromParentAndCleanup(true);
		canCollect = false;
	}
}
