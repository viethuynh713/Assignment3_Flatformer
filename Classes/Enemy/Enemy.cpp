#include "Enemy.h"
#include "cocos2d.h"

Enemy::Enemy()
{
    m_id = rand() % 51;
    m_position = cocos2d::Vec2(20.0, 20.0);
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

bool operator==(Enemy const& i_enemy, Enemy const& o_enemy)
{
    return i_enemy.m_id == o_enemy.m_id && i_enemy.m_position == o_enemy.m_position;
}
