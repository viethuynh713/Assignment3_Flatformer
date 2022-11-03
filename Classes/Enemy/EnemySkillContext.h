#pragma once

#include "EnemySkillStrategy.h"
#include "cocos2d.h"

class EnemySkillContext {
public:
	EnemySkillContext();
	~EnemySkillContext();
	void setStrategy(EnemySkillStrategy& i_strategy);
	void executeStrategy(const cocos2d::Vec2& i_position);
private:
	std::vector<std::string> m_skillList;
};