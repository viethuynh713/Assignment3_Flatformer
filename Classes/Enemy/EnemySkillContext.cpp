#include "EnemySkillContext.h"
#include "cocos2d.h"

EnemySkillContext::EnemySkillContext()
{
}

EnemySkillContext::~EnemySkillContext()
{
}

void EnemySkillContext::setStrategy(EnemySkillStrategy& i_strategy)
{
	m_skillList = i_strategy.GetSkill();
}

void EnemySkillContext::executeStrategy(const cocos2d::Vec2& i_position)
{
	if (m_skillList.size() == 1)
	{
		// play Animation
	}
	else
	{
		int randomIdx = rand() % (m_skillList.size() + 1) - 1;
		
	}
}

