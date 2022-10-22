#include "EnemyManager.h"

void EnemyManager::RemoveEnemy(const IEnemy& i_enemy)
{
	m_enemys.pop_back();
}

void EnemyManager::Update()
{
}

void EnemyManager::AddEnemy(const IEnemy& i_enemy)
{
	m_enemys.emplace_back(i_enemy);
}
