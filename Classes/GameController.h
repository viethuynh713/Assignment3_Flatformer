#pragma once

#include "cocos2d.h"
#include "Item/ItemManager.h"
#include "Player/Player.h"
#include "Enemy/EnemyManager.h"

class GameController {
public:
	GameController();
	~GameController();
	void InitGame();
	void Play();
	void EndGame();
	void Restart();
	void Pause();
private:
	enum GameState {
		INIT,
		PLAYING,
		PAUSE,
		EXIT
	};
	std::unique_ptr<EnemyManager> m_enemyManager;
	std::unique_ptr<ItemManager> m_itemManager;
	std::unique_ptr<Player> m_player;
	GameState m_gameState;
};