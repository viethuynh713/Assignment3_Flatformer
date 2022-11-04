#include "Enemy.h"
#include "cocos2d.h"

Enemy::Enemy(cocos2d::Vec2 pos)
{
    m_id = rand() % 51;
    this->initWithFile("Enemy/Golem/golemIdle.png");
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(pos);
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

//bool operator==(Enemy& i_enemy, Enemy& o_enemy)
//{
//    return i_enemy.m_id == o_enemy.m_id && i_enemy.m_position == o_enemy.m_position;
//}
