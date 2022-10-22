#pragma once

#include "cocos2d.h"

class EnemySkillStrategy {
public:
	virtual void attack(const cocos2d::Vec2& m_position);
};