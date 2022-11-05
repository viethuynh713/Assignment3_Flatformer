#pragma once
#include "PlayerAttackContext.h"
#include "cocos2d.h"
using namespace cocos2d;
class Player : public cocos2d::Sprite {
public:
	Player();
	~Player();
	void loop();
	void attack();
	void changeWeapon();
	void changeHP(int dental);
	void learnSkill();
	void die();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void addLive();
	void addSpeed();
	void addStar();
	void addCoin();
	int getNKey();
	void addKey(int nKeyAdd);
	void removeKey(int nKeyRemove);
	bool isAttack();
	int getHP();
	cocos2d::EventListenerKeyboard* getListenerKeyboard();

	void resetJumpState();
	cocos2d::Label* getHPText();
	cocos2d::Label* getCoinText();
	cocos2d::Label* getStarText();
	void setHPText();
	void setCoinText();
	void setStarText();
	void setIsPlaying(bool isPlaying);
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
	MoveDirection m_prevMoveDirection;
	MoveDirection m_moveDirection;
	int m_coin;
	int m_star;
	std::unique_ptr<PlayerAttackContext> m_playerAttackContext;
	bool m_canGetDmg;
	float m_jumpForce;
	bool m_isSitting;
	bool m_isJumping;
	bool m_isAttacking;
	State m_state;
	std::string m_currentWeapon;
	int nKey;
	cocos2d::PhysicsBody* physicsBody;
	cocos2d::EventListenerKeyboard* listenerKeyboard;

	bool isPlaying;

	cocos2d::Sprite* spriteAnimation;
	cocos2d::Label* hpText;
	cocos2d::Label* coinText;
	cocos2d::Label* starText;

	void jump();
	cocos2d::Animation* getAnimate(const std::string& plist, const char* format, int count);
	Vector<SpriteFrame*> getAnimation(const char* format, int count);
};