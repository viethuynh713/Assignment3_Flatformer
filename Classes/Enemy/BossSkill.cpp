#include "BossSkill.h"

BossSkill::BossSkill()
{
	m_skill = SkillList("Boss").GetSkill();
}

BossSkill::~BossSkill()
{
}

void BossSkill::play(const cocos2d::Vec2& m_position)
{
}

const std::vector<std::string> BossSkill::GetSkill()
{
	return m_skill;
}
