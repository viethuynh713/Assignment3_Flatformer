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
	void ChangeSkill();

private:
	std::vector<PlayerAttackStrategy> m_strategyList;
	int m_currentIdx;

};