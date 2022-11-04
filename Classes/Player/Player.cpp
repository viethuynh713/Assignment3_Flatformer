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
	this->m_speed = 5;
	//this->m_hixBox = Rect::setRect((float)0, (float)0, (float)100, (float)100);
	this->m_moveDirection = MoveDirection::NONE;
	this->m_position = INIT_POSITION;
	this->m_playerAttackContext = std::make_unique<PlayerAttackContext>();
	this->m_timeNoDie = 1;
	this->m_isJumping = false;
	this->m_isSitting = false;
	this->m_isAttacking = false;
	listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);

	// create image
	auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
	float tileSizeWidth = sampleTile->getContentSize().width;
	float tileSizeHeight = sampleTile->getContentSize().height;
	this->initWithFile("Player/Idle/SNinja_idle1.png");
	this->setOpacity(0);

	// play animation
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Player/Idle/idle.plist");
	auto frames = getAnimation("SNinja_idle%01d.png", 6);
	spriteAnimation = Sprite::createWithSpriteFrame(frames.front());
	this->addChild(spriteAnimation);
	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 6);
	spriteAnimation->runAction(RepeatForever::create(Animate::create(animation)));

	// create physics
	auto sampleSize = Sprite::create("Player/Idle/SNinja_idle1.png");
	physicsBody = PhysicsBody::createBox(
		Size(sampleSize->getContentSize().width, sampleSize->getContentSize().height), PhysicsMaterial(0.1f, 0.0f, 0.0f)
	);
	physicsBody->setRotationEnable(false);
	this->addComponent(physicsBody);
	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(cocos2d::Vec2(tileSizeWidth * 1, tileSizeHeight * 24));
	spriteAnimation->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
}

Player::~Player()
{
}

void Player::loop()
{
	switch (this->m_moveDirection)
	{
	case MoveDirection::LEFT:
		this->setFlippedX(true);
		this->runAction(MoveBy::create(0.2, Vec2(-m_speed, 0)));
		break;
	case MoveDirection::RIGHT:
		this->setFlippedX(false);
		this->runAction(MoveBy::create(0.2, Vec2(m_speed, 0)));
		break;
	case MoveDirection::UP:
		
		break;
	case MoveDirection::DOWN:
		this->runAction(MoveBy::create(0.2, Vec2(0, 0)));
		break;
	default:
		break;
	}
	// move map
	if (this->getPosition().x > -this->getParent()->getPosition().x + 980) {
		this->getParent()->runAction(MoveBy::create(0.2, Vec2(-m_speed, 0)));
	}
	if (this->getPosition().x < -this->getParent()->getPosition().x + 300) {
		this->getParent()->runAction(MoveBy::create(0.2, Vec2(m_speed, 0)));
	}
	if (this->getPosition().y > -this->getParent()->getPosition().y + 620) {
		this->getParent()->runAction(MoveBy::create(0.2, Vec2(0, -m_speed)));
	}
	if (this->getPosition().y < -this->getParent()->getPosition().y + 100) {
		this->getParent()->runAction(MoveBy::create(0.2, Vec2(0, m_speed)));
	}
}

void Player::jump() {
	if (!m_isJumping) {
		physicsBody->setVelocity(Vec2(0, 200));
		m_isJumping = true;
		cocos2d::DelayTime* delay = cocos2d::DelayTime::create(2);
		auto callbackJump = CallFunc::create([this]() {
			m_isJumping = false;
		});
		runAction(cocos2d::Sequence::create(delay, callbackJump, nullptr));
	}
}

void Player::resetJumpState() {
	m_isJumping = false;
}

void Player::attack()
{
	auto attackAnimation = this->m_playerAttackContext->ExecuteStategy(this->m_position, this->m_moveDirection);
	spriteAnimation->stopAllActions();
	auto attack = Animate::create(attackAnimation);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Player/Idle/idle.plist");
	auto frames = getAnimation("SNinja_idle%01d.png", 6);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 6);
	auto idle = RepeatForever::create(Animate::create(animation));

	auto callbackAttack = CallFunc::create([this]() {
		m_isAttacking = false;
	});
	
	m_isAttacking = true;
	auto seq = Sequence::create(attack, callbackAttack, idle, nullptr);
	spriteAnimation->runAction(seq);
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
		jump();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
	{
		m_moveDirection = MoveDirection::LEFT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
	{
		m_moveDirection = MoveDirection::RIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		m_moveDirection = MoveDirection::DOWN;
	}
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_D
		|| keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		m_moveDirection = MoveDirection::NONE;
	}
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

bool Player::isAttack() {
	return m_isAttacking;
}

cocos2d::EventListenerKeyboard* Player::getListenerKeyboard() {
	return listenerKeyboard;
}

Vector<SpriteFrame*> Player::getAnimation(const char* format, int count)
{
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;
}