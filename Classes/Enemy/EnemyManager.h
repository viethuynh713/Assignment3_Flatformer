#pragma once
#include "IEnemy.h"
#include "cocos2d.h"


class EnemyManager {
public:
	void RemoveEnemy(const IEnemy& i_enemy);
	void Update();
	void AddEnemy(const IEnemy& i_enemy);
private:
	std::vector<IEnemy> m_enemys;
};