#pragma once
#pragma warning

#include "cocos2d.h"
enum class MoveDirection
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class PlayerAttackStrategy {
public:
	PlayerAttackStrategy();
	~PlayerAttackStrategy();
	virtual void attack(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection) = 0;
};