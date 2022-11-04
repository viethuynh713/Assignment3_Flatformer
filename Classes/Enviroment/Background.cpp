#include "Background.h"

USING_NS_CC;

Background::Background(float x, float y, std::string nameObject) {
	canDestroy = false;
	coverKey = false;
	isKey = false;
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
			this->setTexture("sprite/door/key.png");
			isKey = true;
		}
		else {
			this->removeFromParentAndCleanup(true);
		}
	}
}

void Background::doInteract(Player* player) {
	if (isKey) {
		player->addKey(1);
		this->removeFromParentAndCleanup(true);
	}
}