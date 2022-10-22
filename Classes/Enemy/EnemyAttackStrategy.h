#pragma once

#include "cocos2d.h"

class EnemyAttackStrategy {
public:
	virtual void attack(const cocos2d::Vec2& m_position) = 0;
};