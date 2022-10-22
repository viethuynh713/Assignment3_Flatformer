#pragma once
#include "PlayerAttackStrategy.h"
#include "cocos2d.h"

class PlayerMeleeAttack : PlayerAttackStrategy {
public:
	PlayerMeleeAttack();
	~PlayerMeleeAttack();
	void attack(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection) override;
};