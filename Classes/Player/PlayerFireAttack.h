#pragma once
#include "PlayerAttackStrategy.h"
#include "cocos2d.h"

class PlayerFireAttack : PlayerAttackStrategy {
public:
	void attack(std::pair<float, float>& i_position, const FaceDirection& m_faceDirection) override final;
};