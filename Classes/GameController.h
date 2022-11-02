#pragma once

#include "cocos2d.h"
#include "Item/ItemManager.h"
#include "Player/Player.h"
#include "Enemy/EnemyManager.h"
#include "Enviroment/MapManager.h"

class GameController: public cocos2d::Layer {
public:
	GameController();
	~GameController();
	virtual bool init();
	void Play();
	void EndGame();
	void Restart();
	void Pause();
	void setPhysicsWorld(cocos2d::PhysicsWorld* world);
private:
	enum GameState {
		INIT,
		PLAYING,
		PAUSE,
		EXIT
	};
	std::unique_ptr<EnemyManager> m_enemyManager;
	ItemManager* m_itemManager;
	std::unique_ptr<Player> m_player;
	MapManager* m_mapManager;
	cocos2d::PhysicsWorld* sceneWorld;
};