#pragma once

#include "EnemySkillStrategy.h"
#include "cocos2d.h"

class EnemySkillContext {
public:
	EnemySkillContext();
	~EnemySkillContext();
	void setStrategy(const EnemySkillStrategy& i_strategy);
	void executeStrategy(const cocos2d::Vec2& i_position);
private:
	std::unique_ptr<EnemySkillStrategy> m_strategy;
	std::vector<EnemySkillStrategy> m_attackStrategyList;
};