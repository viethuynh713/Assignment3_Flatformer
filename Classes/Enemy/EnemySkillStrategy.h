#pragma once

#include "cocos2d.h"
#include "SkillList.h"


class RatSkill;
class BatSkill;
class GolemSkill;
class BossSkill;
class EnemySkillStrategy {
public:
	EnemySkillStrategy();
	~EnemySkillStrategy();
	virtual void play(const cocos2d::Vec2& m_position) = 0;
	virtual const std::vector<std::string> GetSkill() = 0;
};