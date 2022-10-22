#pragma once


#include "IEnemy.h"
#include "EnemyAttackStrategy.h"
#include "EnemyAttackContext.h"
#include "../Player/Player.h"
#include "cocos2d.h"

class EnemyAttackContext;
class EnemyAttackStrategy;

class Enemy : public IEnemy {
public:
	Enemy();
	~Enemy();
	virtual void die() override;
	virtual void attack() override;
	virtual void move() override;
	virtual void canAttack(const Player& i_player) override;
private:
	std::string m_id;
	cocos2d::Vec2 m_position;
	std::shared_ptr<EnemyAttackContext> m_attackStrategy;
	std::vector<EnemyAttackStrategy> m_attackStrategyList;
};