#include "Player.h"
#define MAX_HP  100;
#define INIT_POSITION Vec2(0,0)

Player::Player()
{
	this->m_lives = 0;
	this->m_HP = MAX_HP;
	this->m_coin = 0;
	this->m_jumpForce = 100;
	this->m_speed = 100;
	//this->m_hixBox = Rect::setRect((float)0, (float)0, (float)100, (float)100);
	this->m_moveDirection = MoveDirection::RIGHT;
	this->m_position = INIT_POSITION;
	this->m_playerAttackContext = std::make_unique<PlayerAttackContext>();
	this->m_timeNoDie = 1;
	this->m_isJumping = false;
	this->m_isSitting = false;
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	
}

Player::~Player()
{
}

void Player::move(const MoveDirection& i_direction)
{
	this->m_moveDirection = i_direction;
	switch (i_direction)
	{
	case MoveDirection::LEFT:
		break;
	case MoveDirection::RIGHT:
		break;
	case MoveDirection::UP:
		break;
	case MoveDirection::DOWN:
		break;
	default:
		break;
	}
}

void Player::attack()
{
	this->m_playerAttackContext->ExecuteStategy(this->m_position,this->m_moveDirection);
}

void Player::changeWeapon()
{
	this->m_playerAttackContext->ChangeSkill();
}

void Player::changeHP(int dental)
{
	this->m_HP -= dental;
	if (m_HP > 100)m_HP = 100;
	if (m_HP <= 0)
	{
		if (this->m_lives - 1 <= 0)
		{
			this->die();
		}
		else
		{
			this->m_lives--;
			this->m_HP = MAX_HP;
			this->m_position = INIT_POSITION;
		}
	}
}

void Player::learnSkill()
{
}

void Player::die()
{
}
void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE && !this->m_isJumping)
	{
		this->move(MoveDirection::UP);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		this->move(MoveDirection::LEFT);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
	{
		this->move(MoveDirection::RIGHT);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		this->move(MoveDirection::DOWN);
	}
}
void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		this->changeWeapon();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_E)
	{
		this->attack();
	}
}
