#include "Trap.h"

USING_NS_CC;

Trap::Trap(float x, float y)
{
	this->initWithFile("sprite/trap/trap.png");
	auto physicsBody = PhysicsBody::createBox(
		Size(this->getContentSize().width, this->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f)
	);
	physicsBody->setDynamic(false);
	this->addComponent(physicsBody);
	this->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(x, y);
	damage = 10;
}

Trap::Trap(float x, float y, int angle) {
	this->initWithFile("sprite/trap/trap.png");
	auto physicsBody = PhysicsBody::createBox(
		Size(this->getContentSize().width, this->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f)
	);
	physicsBody->setDynamic(false);
	this->addComponent(physicsBody);
	this->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	damage = 10;
	this->setAnchorPoint(Vec2(0.5, this->getContentSize().width * 0.5 / this->getContentSize().height));
	this->setPosition(x + this->getContentSize().width / 2, y + this->getContentSize().width / 2);
	this->setRotation(angle);
}

Trap::~Trap()
{

}

void Trap::doInteract(Player* player) {
	player->changeHP(-damage);
}