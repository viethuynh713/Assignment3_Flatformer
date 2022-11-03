#include "PlayerAttackContext.h"
#include "Player/PlayerAttackStrategy.h"
#include "PlayerFireAttack.h"

PlayerAttackContext::PlayerAttackContext()
{
	m_strategy = std::vector<std::string>();
	m_strategy.push_back("Melee");
	
	//this->m_strategyList.push_back(std::make_unique<PlayerFireAttack>());
	this->m_currentIdx = 0;
	//this->m_strategyList.push_back(new PlayerFireAttack())
}

PlayerAttackContext::~PlayerAttackContext()
{
}

void PlayerAttackContext::SetStrategy(std::string i_strategy)
{
	this->m_strategyList.push_back(i_strategy);
}

void PlayerAttackContext::ExecuteStategy(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection)
{
	this->m_strategyList.at(this->m_currentIdx).attack(i_position, i_moveDirection);
}
void PlayerAttackContext::ChangeSkill()
{
	this->m_currentIdx++;
	if (this->m_currentIdx >= this->m_strategyList.size())
	{
		m_currentIdx = 0;
	}
}

int PlayerAttackContext::GetNumSkill()
{
	return m_strategy.size();
}
