#include "PlayerAttackContext.h"
#include "Player/PlayerAttackStrategy.h"

PlayerAttackContext::PlayerAttackContext()
{
	m_strategy = std::vector<std::string>();
	m_strategy.push_back("Melee");
}

PlayerAttackContext::~PlayerAttackContext()
{
}

void PlayerAttackContext::SetStrategy(std::string i_strategy)
{
	m_strategy.push_back(i_strategy);
}

cocos2d::Animation* PlayerAttackContext::ExecuteStategy(const cocos2d::Vec2& i_position, const MoveDirection& i_moveDirection)
{
	std::string plist = "Player/Attack/NormalAttack/melee_attack.plist";
	char* png = "SNinja_Atk%01d.png";
	if (i_moveDirection == MoveDirection::LEFT) {
		plist = "Player/Attack/NormalAttack/melee_attack_left.plist";
		png = "SNinja_Atk_left%01d.png";
	}
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
	auto frames = getAnimation(png, 7);
	auto sprite = cocos2d::Sprite::createWithSpriteFrame(frames.front());
	auto animation = cocos2d::Animation::createWithSpriteFrames(frames, 1.0f / 7);
	return animation;
}

int PlayerAttackContext::GetNumSkill()
{
	return m_strategy.size();
}

cocos2d::Vector<cocos2d::SpriteFrame*> PlayerAttackContext::getAnimation(const char* format, int count)
{
	auto spritecache = cocos2d::SpriteFrameCache::getInstance();
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;
}