#pragma once
#include "Enemy.h"
#include "cocos2d.h"


class EnemyManager {
public:
	EnemyManager();
	~EnemyManager();
	void RemoveEnemy(const Enemy& i_enemy);
	void Update();
	void AddEnemy(const Enemy& i_enemy);
	void generateEnemy();
private:
	std::vector<Enemy> m_enemys;

};