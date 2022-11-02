#include "Ground.h"

USING_NS_CC;

Ground::Ground(float x, float y)
{
	this->initWithFile("sprite/ground/ground_top.png");
	auto physicsBody = PhysicsBody::createBox(
		Size(this->getContentSize().width, this->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f)
	);
	physicsBody->setDynamic(false);
	this->addComponent(physicsBody);
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(x, y);
}

Ground::~Ground()
{

}