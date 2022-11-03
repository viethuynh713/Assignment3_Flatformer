#include "RatSkill.h"

RatSkill::RatSkill()
{
	m_skill = SkillList("Rat").GetSkill();
}

RatSkill::~RatSkill()
{
	m_skill.clear();
}

void RatSkill::play(const cocos2d::Vec2& m_position)
{
}

const std::vector<std::string> RatSkill::GetSkill()
{
	return m_skill;
}
