#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::RemoveEnemy(const Enemy& i_enemy)
{
	for (std::vector<Enemy>::iterator i = m_enemys.begin() ; i != m_enemys.end(); i++)
	{
		if (*i == i_enemy)
		{
			m_enemys.erase(i);
		}
	}
}

void EnemyManager::Update()
{
	// Animation
}

void EnemyManager::AddEnemy(const Enemy& i_enemy)
{
	m_enemys.emplace_back(i_enemy);
}

void EnemyManager::generateEnemy()
{

}
