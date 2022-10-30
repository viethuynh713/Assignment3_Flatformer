#pragma once

#include "EnemySkillStrategy.h"
#include "cocos2d.h"

class BossSkill : public EnemySkillStrategy {
public:
	BossSkill();
	~BossSkill();
	void play(const cocos2d::Vec2& m_position) override;
	const std::vector<std::string> GetSkill() override;
private:
	std::vector<std::string> m_skill;
};