#pragma once

#include "IEnemy.h"
#include "cocos2d.h"

class Rat : IEnemy {
public:
	void die() override;
	void attack() override;
	void move() override;
	void canAttack(const Player& i_player) override;
private:
	std::string m_id;
	std::pair<float, float> m_position;
	std::shared_ptr<EnemyAttackContext> m_attackStrategy;
	std::vector<EnemyAttackStrategy> m_attackStrategyList;
};