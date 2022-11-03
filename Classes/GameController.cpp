#include "GameController.h"

USING_NS_CC;

GameController::GameController()
{
	m_enemyManager = new EnemyManager();
	this->addChild(m_enemyManager);
	m_itemManager = new ItemManager();
	this->addChild(m_itemManager);
	m_mapManager = new MapManager();
	this->addChild(m_mapManager);
	m_player = new Player();
	this->addChild(m_player);
	sceneWorld = nullptr;
}

GameController::~GameController()
{
	delete[] m_player;
	delete[] m_itemManager;
	delete[] m_mapManager;
}

bool GameController::init()
{
	if (!Layer::init()) {
		return false;
	}

	return true;
}

void GameController::Play()
{
}

void GameController::EndGame()
{
}

void GameController::Restart()
{
}

void GameController::Pause()
{
}

void GameController::setPhysicsWorld(cocos2d::PhysicsWorld* world) {
	sceneWorld = world;
}

ItemManager* GameController::getItemManager() {
	return m_itemManager;
}