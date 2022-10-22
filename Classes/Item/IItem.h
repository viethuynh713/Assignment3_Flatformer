#pragma once

#include "cocos2d.h"

class IItem {
public:
	virtual void applyEffect() const = 0;
};
