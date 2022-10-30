#pragma once


#include "../Player/Player.h"
#include "EnemySkillContext.h"
#include "cocos2d.h"

class Enemy{
public:
	Enemy();
	~Enemy();
	void die(const Player& i_player);
	void attack();
	void move();
	void canAttack(const Player& i_player);
	friend bool operator==(Enemy const& i_enemy, Enemy const& o_enemy);
private:
	int m_id;
	cocos2d::Vec2 m_position;
	std::shared_ptr<EnemySkillContext> m_EnemySkillContext;
};