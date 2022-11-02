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