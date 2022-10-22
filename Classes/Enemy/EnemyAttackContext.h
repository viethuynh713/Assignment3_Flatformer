#pragma once

#include "EnemyAttackStrategy.h"
#include "cocos2d.h"

class EnemyAttackContext {
public:
	void setStrategy(const EnemyAttackStrategy& i_strategy);
	void executeStrategy(std::pair<float, float>& i_position);
private:
	std::unique_ptr<EnemyAttackStrategy> m_strategy;
};