#include "Player.h"
#include "PlayerAttackContext.h"
#define MAX_HP  100;
#define INIT_POSITION Vec2(0,0)

Player::Player()
{
	this->m_lives = 0;
	this->m_HP = MAX_HP;
	this->m_coin = 0;
	this->m_jumpForce = 100;
	this->m_speed = 10;
	//this->m_hixBox = Rect::setRect((float)0, (float)0, (float)100, (float)100);
	this->m_moveDirection = MoveDirection::RIGHT;
	this->m_position = INIT_POSITION;
	this->m_playerAttackContext = std::make_unique<PlayerAttackContext>();
	this->m_timeNoDie = 1;
	this->m_isJumping = false;
	this->m_isSitting = false;
	listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);

	// create image
	auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
	float tileSizeWidth = sampleTile->getContentSize().width;
	float tileSizeHeight = sampleTile->getContentSize().height;
	this->initWithFile("Player/Idle/SNinja_idle1.png");
	auto physicsBody = PhysicsBody::createBox(
		Size(this->getContentSize().width, this->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f)
	);
	physicsBody->setDynamic(true);
	this->addComponent(physicsBody);
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(cocos2d::Vec2(tileSizeWidth * 1, tileSizeHeight * 24));
}

Player::~Player()
{
}

void Player::move(const MoveDirection& i_direction)
{
	while (true) {
		this->m_moveDirection = i_direction;
		switch (i_direction)
		{
		case MoveDirection::LEFT:
			this->runAction(MoveBy::create(0.1, Vec2(-m_speed, 0)));
			break;
		case MoveDirection::RIGHT:
			this->runAction(MoveBy::create(0.1, Vec2(m_speed, 0)));
			break;
		case MoveDirection::UP:
			break;
		case MoveDirection::DOWN:
			break;
		default:
			break;
		}
	}
}

void Player::attack()
{
	this->m_playerAttackContext->ExecuteStategy(this->m_position,this->m_moveDirection);
}

void Player::changeWeapon()
{
	if (m_playerAttackContext->GetNumSkill() < 2)
	{
		return;
	}
	else 
	{
		if (m_currentWeapon == "Melee")
		{
			m_currentWeapon = "Fire";
		}
		else
		{
			m_currentWeapon = "Melee";
		}
	}
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
	m_playerAttackContext->SetStrategy("Fire");
}

void Player::die()
{
}
void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W && !this->m_isJumping)
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

void Player::addLive()
{
	m_lives += 10;
}

void Player::addSpeed()
{
	m_speed += 10;
}

int Player::getNKey() {
	return nKey;
}

void Player::addKey(int nKeyAdd) {
	nKey += nKeyAdd;
}

void Player::removeKey(int nKeyRemove) {
	if (nKeyRemove <= nKey) {
		nKey -= nKeyRemove;
	}
}

cocos2d::EventListenerKeyboard* Player::getListenerKeyboard() {
	return listenerKeyboard;
}