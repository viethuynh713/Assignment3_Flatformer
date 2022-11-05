#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	m_enemys = std::vector<Enemy*>();
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::RemoveEnemy(Enemy* i_enemy)
{
	for (int i = 0; i < m_enemys.size(); i++)
	{
		if (m_enemys.at(i)->m_id == i_enemy->m_id)
		{
			this->removeChild(m_enemys.at(i));
			m_enemys.erase(m_enemys.begin() + i);
		}
	}
}

void EnemyManager::Update()
{
	// Animation
}

void EnemyManager::AddEnemy(Enemy* i_enemy)
{
	m_enemys.emplace_back(i_enemy);
	this->addChild(i_enemy);
}

void EnemyManager::generateEnemy()
{

}

void EnemyManager::checkCollide(Player* player) {
	std::vector<Enemy*> enemyRemoveIdx = std::vector<Enemy*>();
	for (Enemy* enemy: m_enemys) {
		if (enemy->isAttacked(player)) {
			if (player->isAttack()) {
				enemyRemoveIdx.push_back(enemy);
			}
			else {
				player->changeHP(enemy->getDmg());
			}
		}
	}
	for (Enemy* enemy : enemyRemoveIdx) {
		log("EnemyManager::checkCollide");
		RemoveEnemy(enemy);
	}
}

bool EnemyManager::isNoEnemy() {
	if (m_enemys.size() == 0) {
		return true;
	}
	return false;
}
