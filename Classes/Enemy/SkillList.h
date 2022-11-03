#pragma once

#include "cocos2d.h"


class SkillList {
public:
	SkillList(const std::string& i_string);
	~SkillList();
	std::vector<std::string> GetSkill();
private:
	std::vector<std::string> m_skillName;
};