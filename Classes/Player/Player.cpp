#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::move(const MoveDirection& i_direction)
{
}

void Player::attack()
{
}

void Player::changeWeapon()
{
}

void Player::changeHP(int HPChange)
{
}

void Player::learnSkill()
{
}

void Player::die()
{
}

void Player::removeKeys(int p_nKey) {
	nKey -= p_nKey;
}

int Player::getNKey() {
	return nKey;
}