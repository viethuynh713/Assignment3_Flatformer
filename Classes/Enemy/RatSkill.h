#pragma once

#include "EnemySkillStrategy.h"
#include "cocos2d.h"

class RatSkill : public EnemySkillStrategy{
public:
	void attack(const cocos2d::Vec2 & m_position) override;
};