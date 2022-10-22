#pragma once
#include "PlayerAttackContext.h"
#include "cocos2d.h"

class PlayerAttackStrategy {
public:
	virtual void attack(std::pair<float, float>& i_position, const FaceDirection& m_faceDirection) = 0;
};