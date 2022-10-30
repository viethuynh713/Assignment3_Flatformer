#include "GolemSkill.h"

GolemSkill::GolemSkill()
{
	m_skill = SkillList("Golem").GetSkill();
}

GolemSkill::~GolemSkill()
{
}

void GolemSkill::play(const cocos2d::Vec2& m_position)
{
}

const std::vector<std::string> GolemSkill::GetSkill()
{
	return m_skill;
}
