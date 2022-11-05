#pragma once


#include "../Player/Player.h"
#include "EnemySkillContext.h"
#include "cocos2d.h"

class Enemy: public cocos2d::Sprite {
public:
	Enemy(cocos2d::Vec2 pos);
	~Enemy();
	void die(const Player& i_player);
	void attack();
	void move();
	void canAttack(const Player& i_player);
	bool isAttacked(Player* player);
	int getDmg();
	//friend bool operator==(Enemy const& i_enemy, Enemy const& o_enemy);
	int m_id;
	cocos2d::Vec2 m_position;
private:
	std::shared_ptr<EnemySkillContext> m_EnemySkillContext;
	int dmg;
};