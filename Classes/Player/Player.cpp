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

void Player::changeHP(int i_hp)
{
	m_HP += i_hp;
}

void Player::learnSkill()
{
	m_playerAttackContext->SetStrategy("Fire");
}

void Player::die()
{
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