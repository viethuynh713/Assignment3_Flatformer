#include "Background.h"
#include "Item/Key.h"

USING_NS_CC;

Background::Background(float x, float y, std::string nameObject) {
	canDestroy = false;
	coverKey = false;
	if (nameObject == "bush") {
		canDestroy = true;
		this->initWithFile("sprite/background/grass.png");
		this->setAnchorPoint(Vec2(0, 0));
		this->setPosition(x, y);
	}
	else if (nameObject == "key") {
		canDestroy = true;
		coverKey = true;
		this->initWithFile("sprite/background/grass.png");
		this->setAnchorPoint(Vec2(0, 0));
		this->setPosition(x, y);
	}
}

Background::~Background()
{
	
}

void Background::destroy() {
	if (canDestroy) {
		if (coverKey) {
			auto key = new Key();
			key->setPosition(this->getPosition());
			this->getParent()->addChild(key);
		}
		this->removeFromParentAndCleanup(true);
	}
}