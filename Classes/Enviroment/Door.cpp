#include "Door.h"

USING_NS_CC;

Door::Door(float x, float y, int p_nKeyNeed)
{
	this->initWithFile("sprite/door/door.png");
	auto physicsBody = PhysicsBody::createBox(
		Size(this->getContentSize().width, this->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f)
	);
	physicsBody->setDynamic(false);
	this->addComponent(physicsBody);
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(x, y);
	nKeyNeed = p_nKeyNeed;
	isOpened = false;
}

Door::~Door()
{
	
}

void Door::doInteract(Player* player) {
	if (!isOpened && player->getNKey() >= this->nKeyNeed) {
		isOpened = true;
		this->open();
		player->removeKey(this->nKeyNeed);
	}
}

void Door::open() {
	this->runAction(MoveBy::create(2, Vec2(0, -this->getContentSize().height)));
}