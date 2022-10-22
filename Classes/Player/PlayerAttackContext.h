#pragma once
#pragma warning
#include "PlayerAttackStrategy.h"
#include "cocos2d.h"

class PlayerAttackContext {
public:
	PlayerAttackContext();
	~PlayerAttackContext();
	void SetStrategy(const PlayerAttackStrategy& i_strategy);
	void ExecuteStategy(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection);

private:
	std::unique_ptr<PlayerAttackStrategy> m_strategy;

};