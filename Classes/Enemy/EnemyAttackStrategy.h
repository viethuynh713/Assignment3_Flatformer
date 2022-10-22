#pragma once

#include "cocos2d.h"

class EnemyAttackStrategy {
public:
	virtual void attack(std::pair<float, float>& m_position) = 0;
};