#include "GameController.h"

USING_NS_CC;

GameController::GameController()
{
	m_mapManager = new MapManager();
	this->addChild(m_mapManager, 0);
	m_enemyManager = new EnemyManager();
	this->m_mapManager->addChild(m_enemyManager, 1);
	m_itemManager = new ItemManager();
	this->m_mapManager->addChild(m_itemManager, 0);
	m_player = new Player();
	this->m_mapManager->addChild(m_player, 1);
	sceneWorld = nullptr;

	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_player->getListenerKeyboard(), this);
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