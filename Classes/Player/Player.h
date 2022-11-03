#pragma once
#include "PlayerAttackContext.h"
#include "cocos2d.h"

class Player: public cocos2d::Sprite {
public:
	Player();
	~Player();
	void move(const MoveDirection& i_direction);
	void attack();
	void changeWeapon();
	void changeHP(int i_hp);
	void learnSkill();
	void die();
	void addLive();
	void addSpeed();
	int getNKey();
	void addKey(int nKeyAdd);
	void removeKey(int nKeyRemove);
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
	State m_state;
	std::string m_currentWeapon;
	int nKey;
};
