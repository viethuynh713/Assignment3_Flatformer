#pragma once

#include "EnemySkillStrategy.h"
#include "SkillList.h"
#include "cocos2d.h"

class BatSkill : public EnemySkillStrategy {
public: 
	BatSkill();
	~BatSkill();
	void play(const cocos2d::Vec2& m_position) override;
	const std::vector<std::string> GetSkill() override;
private:
	std::vector<std::string> m_skill;
};