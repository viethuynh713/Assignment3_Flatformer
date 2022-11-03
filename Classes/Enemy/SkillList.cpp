#include "SkillList.h"

SkillList::SkillList(const std::string& i_string)
{
	if (i_string == "Bat")
	{
		m_skillName = std::vector<std::string>();
	}
	else if (i_string == "Rat")
	{
		m_skillName = std::vector<std::string>();
	}
	else if (i_string == "Golem")
	{
		m_skillName = std::vector<std::string>();
	}
	else if (i_string == "Boss")
	{
		m_skillName = std::vector<std::string>();
	}
	else
		m_skillName = std::vector<std::string>();
}

SkillList::~SkillList()
{
}

std::vector<std::string> SkillList::GetSkill()
{
	return m_skillName;
}
