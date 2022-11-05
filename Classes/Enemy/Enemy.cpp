#include "Enemy.h"
#include "cocos2d.h"

Enemy::Enemy(cocos2d::Vec2 pos)
{
    m_id = rand() % 51;
    this->initWithFile("Enemy/Golem/golemIdle.png");
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(pos);
	dmg = 5;

	auto moveRight = MoveBy::create(2, Vec2(160, 0));
	auto moveLeft = MoveBy::create(2, Vec2(-160, 0));
	auto move = Sequence::create(moveRight, moveLeft, nullptr);
	this->runAction(RepeatForever::create(move));
}

Enemy::~Enemy()
{
}

void Enemy::die(const Player& i_player)
{
}

void Enemy::attack()
{
}

void Enemy::move()
{

}

void Enemy::canAttack(const Player& i_player)
{
}

bool Enemy::isAttacked(Player* player) {
	auto boundingBox = this->getBoundingBox();
	auto playerBoundingBox = player->getBoundingBox();
	if (boundingBox.intersectsRect(playerBoundingBox)) {
		log("Enemy::isAttacked");
		return true;
	}
	return false;
}

int Enemy::getDmg() {
	return dmg;
}

//bool operator==(Enemy& i_enemy, Enemy& o_enemy)
//{
//    return i_enemy.m_id == o_enemy.m_id && i_enemy.m_position == o_enemy.m_position;
//}
