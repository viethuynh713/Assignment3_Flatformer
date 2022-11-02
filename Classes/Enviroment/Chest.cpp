#include "Chest.h"

USING_NS_CC;

Chest::Chest(float x, float y, std::vector<Item*> p_rewardList)
{
	this->initWithFile("sprite/chest/chest_close.png");
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(x, y);
	rewardList = p_rewardList;
	isClosing = true;
}

Chest::~Chest()
{
	for (auto i : rewardList) {
		delete[] i;
	}
}

void Chest::doInteract(Player& player) {
	if (isClosing) {
		for (auto i : rewardList) {
			i->applyEffect(player);
		}
		isClosing = false;
		this->setTexture("sprite/chest/chest_open.png");
	}
}