#pragma once
#include "Enemy.h"
#include "cocos2d.h"


class EnemyManager: public cocos2d::Layer {
public:
	EnemyManager();
	~EnemyManager();
	void RemoveEnemy(Enemy* i_enemy);
	void Update();
	void AddEnemy(Enemy* i_enemy);
	void generateEnemy();
	void checkCollide(Player* player);
private:
	std::vector<Enemy*> m_enemys;

};