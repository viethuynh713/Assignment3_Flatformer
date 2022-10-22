#pragma once
#include "PlayerAttackContext.h"
#include "PlayerAttackStrategy.h"
#include "cocos2d.h"

class MoveDirection {

};
class FaceDirection {

};

class Player {
public:
	void move(const MoveDirection& i_direction);
	void attack();
	void changeWeapon();
	void changeHP();
	void learnSkill(const PlayerAttackStrategy& i_skill);
	void die();
private:
	enum State {
		JUMPING,
		SITTING,
		RUNNING
	};
	
	int m_lives;
	int m_HP;
	std::pair<float, float> m_position;
	RECT m_hixBox;
	float m_speed;
	int m_coin;
	std::unique_ptr<PlayerAttackContext> m_playerAttackContext;
	float m_timeNoDie;
	float m_jumpForce;
	State m_state;
};