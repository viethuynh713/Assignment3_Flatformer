#pragma once
#include "Player.h"
#include "cocos2d.h"


class PlayerAttackContext {
public:
	void SetStrategy(const PlayerAttackStrategy& i_strategy);
	void ExecuteStategy(std::pair<float, float>& i_position, const FaceDirection& i_faceDirection);

private:
	std::unique_ptr<PlayerAttackStrategy> m_strategy;

};