#pragma once

#include "Enemy.h"
#include "cocos2d.h"

class Bat : public Enemy {
public: 
	void die() override;
	void attack() override;
	void move() override;
	void canAttack(const Player& i_player) override;
};