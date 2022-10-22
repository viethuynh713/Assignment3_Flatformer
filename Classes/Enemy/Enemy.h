#pragma once


#include "IEnemy.h"
#include "EnemySkillContext.h"
#include "../Player/Player.h"
#include "cocos2d.h"

class Enemy : public IEnemy {
public:
	Enemy();
	~Enemy();
	void die() override;
	void attack() override;
	void move() override;
	void canAttack(const Player& i_player) override;
private:
	std::string m_id;
	cocos2d::Vec2 m_position;
	std::shared_ptr<EnemySkillContext> m_EnemySkillContext;
};