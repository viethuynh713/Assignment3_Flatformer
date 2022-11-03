#include "PlayerAttackContext.h"
#include "Player/PlayerAttackStrategy.h"

PlayerAttackContext::PlayerAttackContext()
{
	m_strategy = std::vector<std::string>();
	m_strategy.push_back("Melee");
}

PlayerAttackContext::~PlayerAttackContext()
{
}

void PlayerAttackContext::SetStrategy(std::string i_strategy)
{
	m_strategy.push_back(i_strategy);
}

void PlayerAttackContext::ExecuteStategy(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection)
{
}

int PlayerAttackContext::GetNumSkill()
{
	return m_strategy.size();
}
