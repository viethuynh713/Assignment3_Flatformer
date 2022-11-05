#include "Player.h"
#include "PlayerAttackContext.h"
#define MAX_HP  100;
#define INIT_POSITION Vec2(80 * 1, 80 * 24)

Player::Player()
{
	this->m_lives = 0;
	this->m_HP = MAX_HP;
	this->m_coin = 0;
	this->m_star = 0;
	this->m_jumpForce = 100;
	this->m_speed = 5;
	//this->m_hixBox = Rect::setRect((float)0, (float)0, (float)100, (float)100);
	this->m_prevMoveDirection = MoveDirection::NONE;
	this->m_moveDirection = MoveDirection::NONE;
	this->m_position = INIT_POSITION;
	this->m_playerAttackContext = std::make_unique<PlayerAttackContext>();
	this->m_canGetDmg = true;
	this->m_isJumping = false;
	this->m_isSitting = false;
	this->m_isAttacking = false;
	isPlaying = true;
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
	auto animation = getAnimate("Player/Idle/idle.plist", "SNinja_idle%01d.png", 6);
	spriteAnimation = Sprite::createWithSpriteFrame(frames.front());
	this->addChild(spriteAnimation);
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

	// create GUI
	std::stringstream ss;
	ss << "HP: " << m_HP;
	hpText = Label::createWithTTF(ss.str(), "fonts/Marker Felt.ttf", 24);
	hpText->setTextColor(cocos2d::Color4B::RED);
	hpText->setPosition(Vec2(120, 700));

	ss.str("");
	ss << "Coin: " << m_coin;
	coinText = Label::createWithTTF(ss.str(), "fonts/Marker Felt.ttf", 24);
	coinText->setTextColor(cocos2d::Color4B::YELLOW);
	coinText->setPosition(Vec2(640, 700));

	ss.str("");
	ss << "Star: " << m_star;
	starText = Label::createWithTTF(ss.str(), "fonts/Marker Felt.ttf", 24);
	starText->setTextColor(cocos2d::Color4B::WHITE);
	starText->setPosition(Vec2(1100, 700));
}

Player::~Player()
{
}

void Player::loop()
{
	cocos2d::Animation* animation;
	switch (this->m_moveDirection)
	{
	case MoveDirection::LEFT:
		if (!m_isAttacking) {
			if (m_prevMoveDirection != MoveDirection::LEFT) {
				spriteAnimation->stopAllActions();
			}
			animation = getAnimate("Player/Idle/idle_left.plist", "SNinja_idle_left%01d.png", 6);
			m_prevMoveDirection = m_moveDirection;
			spriteAnimation->runAction(RepeatForever::create(Animate::create(animation)));
			this->runAction(MoveBy::create(0.2, Vec2(-m_speed, 0)));
		}
		break;
	case MoveDirection::RIGHT:
		if (!m_isAttacking) {
			if (m_prevMoveDirection != MoveDirection::RIGHT) {
				spriteAnimation->stopAllActions();
			}
			animation = getAnimate("Player/Idle/idle.plist", "SNinja_idle%01d.png", 6);
			m_prevMoveDirection = m_moveDirection;
			spriteAnimation->runAction(RepeatForever::create(Animate::create(animation)));
			this->runAction(MoveBy::create(0.2, Vec2(m_speed, 0)));
		}
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
	if (!m_isJumping && isPlaying) {
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
	auto attackAnimation = this->m_playerAttackContext->ExecuteStategy(this->m_position, this->m_prevMoveDirection);
	spriteAnimation->stopAllActions();
	auto attack = Animate::create(attackAnimation);

	auto animation = getAnimate("Player/Idle/idle.plist", "SNinja_idle%01d.png", 6);
	auto idle = RepeatForever::create(Animate::create(animation));

	auto attackSample = Sprite::create("Player/Attack/NormalAttack/SNinja_Atk1.png");
	float attackWidth = attackSample->getContentSize().width;
	auto idleSample = Sprite::create("Player/Idle/SNinja_idle1.png");
	float idleWidth = idleSample->getContentSize().width;

	auto callbackReadyToAttack = CallFunc::create([this, attackWidth]() {
		m_isAttacking = true;
		setContentSize(cocos2d::Size(attackWidth, getContentSize().height));
	});

	auto callbackAttack = CallFunc::create([this, idleWidth]() {
		setContentSize(cocos2d::Size(idleWidth, getContentSize().height));
		m_isAttacking = false;
	});
	
	auto seq = Sequence::create(callbackReadyToAttack, attack, callbackAttack, idle, nullptr);
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
	if (m_canGetDmg) {
		m_canGetDmg = false;
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
		auto callbackCanGetDmg = CallFunc::create([this]() {
			m_canGetDmg = true;
		});
		cocos2d::DelayTime* delay = cocos2d::DelayTime::create(3);
		this->runAction(Sequence::create(delay, callbackCanGetDmg, nullptr));
		setHPText();
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
	//m_lives += 10;
	changeHP(-10);
}

void Player::addSpeed()
{
	m_speed += 10;
}

void Player::addCoin() {
	m_coin++;
	setCoinText();
}

void Player::addStar() {
	m_star++;
	setStarText();
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

int Player::getHP() {
	return m_HP;
}

cocos2d::Label* Player::getHPText() {
	return hpText;
}

cocos2d::Label* Player::getCoinText() {
	return coinText;
}

cocos2d::Label* Player::getStarText() {
	return starText;
}

void Player::setHPText() {
	std::stringstream ss;
	ss << "HP: " << m_HP;
	hpText->setString(ss.str());
}

void Player::setCoinText() {
	std::stringstream ss;
	ss << "Coin: " << m_coin;
	coinText->setString(ss.str());
}

void Player::setStarText() {
	std::stringstream ss;
	ss << "Star: " << m_star;
	starText->setString(ss.str());
}

void Player::setIsPlaying(bool isPlaying) {
	this->isPlaying = isPlaying;
}

cocos2d::EventListenerKeyboard* Player::getListenerKeyboard() {
	return listenerKeyboard;
}

cocos2d::Animation* Player::getAnimate(const std::string& plist, const char* format, int count)
{
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
	auto frames = getAnimation(format, count);
	auto sprite = cocos2d::Sprite::createWithSpriteFrame(frames.front());
	auto animation = cocos2d::Animation::createWithSpriteFrames(frames, 1.0f / count);
	return animation;
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