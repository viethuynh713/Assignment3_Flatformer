#pragma once
#include "../Player/Player.h"
#include "EnemyAttackContext.h"
#include "cocos2d.h"

class IEnemy {
public:
	virtual void die() = 0;
	virtual void attack() = 0;
	virtual void move() = 0;
	virtual void canAttack(const Player& i_player) = 0;
};