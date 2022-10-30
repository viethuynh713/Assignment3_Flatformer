#include "BatSkill.h"

BatSkill::BatSkill()
{
	m_skill = SkillList("Bat").GetSkill();
}

BatSkill::~BatSkill()
{
}

void BatSkill::play(const cocos2d::Vec2& m_position)
{
}

const std::vector<std::string> BatSkill::GetSkill()
{
	return m_skill;
}
