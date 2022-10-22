#pragma once
#include "../Player/Player.h"
#include "EnemySkillContext.h"
#include "cocos2d.h"

__interface IEnemy
{
public:
	virtual void die() = 0;
	virtual void attack() = 0;
	virtual void move() = 0;
	virtual void canAttack(const Player& i_player) = 0;
};