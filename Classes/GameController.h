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
	virtual bool initWithPhysics();
	virtual void update(float dt);
	void Play();
	void EndGame();
	void Restart();
	void Pause();
	void setPhysicsWorld(cocos2d::PhysicsWorld* world);
	ItemManager* getItemManager();
private:
	enum GameState {
		INIT,
		PLAYING,
		PAUSE,
		EXIT
	};
	EnemyManager* m_enemyManager;
	ItemManager* m_itemManager;
	Player* m_player;
	MapManager* m_mapManager;
	cocos2d::PhysicsWorld* sceneWorld;
};