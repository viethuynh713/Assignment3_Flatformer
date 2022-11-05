#pragma once

#include "cocos2d.h"
#include "Item/ItemManager.h"
#include "Player/Player.h"
#include "Enemy/EnemyManager.h"
#include "Enviroment/MapManager.h"
#include "ui/CocosGUI.h"

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
	void Resume();
	void setPhysicsWorld(cocos2d::PhysicsWorld* world);
	void SetUi();
	void SetVolume(bool isNewVolume);
	ItemManager* getItemManager();
private:
	enum GameState {
		INIT,
		PLAYING,
		PAUSE,
		END
	};
	GameState state;
	EnemyManager* m_enemyManager;
	ItemManager* m_itemManager;
	Player* m_player;
	MapManager* m_mapManager;
	cocos2d::PhysicsWorld* sceneWorld;

	cocos2d::Sprite* background;
	cocos2d::Sprite* menuInit;
	cocos2d::Sprite* optionPnl;
	cocos2d::ui::Button* muteVolume;
	cocos2d::ui::Button* volume;

	cocos2d::ui::Button* volumePlaying;
	cocos2d::ui::Button* muteVolumePlaying;
	//Vector< cocos2d::Sprite> listHeart;

	cocos2d::Sprite* playingPnl;
	cocos2d::Sprite* settingPnl;
	cocos2d::Sprite* endgamePnl;
	bool m_isVolume = false;
};