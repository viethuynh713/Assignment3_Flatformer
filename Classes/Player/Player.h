#pragma once
#include "PlayerAttackContext.h"
#include "cocos2d.h"
using namespace cocos2d;
class Player {
public:
	Player();
	~Player();
	void move(const MoveDirection& i_direction);
	void attack();
	void changeWeapon();
	void changeHP(int dental);
	void learnSkill();
	void die();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
private:
	enum State {
		JUMPING,
		SITTING,
		RUNNING
	};
	
	int m_lives;
	int m_HP;
	cocos2d::Vec2 m_position;
	RECT m_hixBox;
	float m_speed;
	MoveDirection m_moveDirection;
	int m_coin;
	std::unique_ptr<PlayerAttackContext> m_playerAttackContext;
	float m_timeNoDie;
	float m_jumpForce;
	bool m_isSitting;
	bool m_isJumping;
};
