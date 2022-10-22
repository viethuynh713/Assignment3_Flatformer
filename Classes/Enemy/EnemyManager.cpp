#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::RemoveEnemy(const Enemy& i_enemy)
{
	m_enemys.pop_back();
}

void EnemyManager::Update()
{
}

void EnemyManager::AddEnemy(const Enemy& i_enemy)
{
	m_enemys.emplace_back(i_enemy);
}
