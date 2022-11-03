
#pragma once
#pragma warning
#include "PlayerAttackStrategy.h"
#include "cocos2d.h"

class PlayerAttackContext {
public:
	PlayerAttackContext();
	~PlayerAttackContext();
	void SetStrategy(std::string i_strategy);
	void ExecuteStategy(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection);
	int GetNumSkill();
private:
	std::vector<std::string> m_strategy;
};