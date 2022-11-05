#include "GameController.h"
#include "ui/CocosGUI.h"

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
	this->addChild(m_player->getHPText(), 2);
	this->addChild(m_player->getCoinText(), 2);
	this->addChild(m_player->getStarText(), 2);

	sceneWorld = nullptr;

	auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
	float tileSizeWidth = sampleTile->getContentSize().width;
	float tileSizeHeight = sampleTile->getContentSize().height;
	
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 4, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 9, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 17, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 33, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 24, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 27, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 30, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 7, tileSizeHeight * 8)));

	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_player->getListenerKeyboard(), this);

	Play();
}

GameController::~GameController()
{
	delete[] m_player;
	delete[] m_itemManager;
	delete[] m_mapManager;
}

bool GameController::initWithPhysics()
{
	if (!Layer::init()) {
		return false;
	}

	return true;
}

void GameController::Play()
{
	scheduleUpdate();
}

void GameController::update(float dt) {
	m_player->loop();
	m_enemyManager->checkCollide(m_player);
	m_mapManager->checkCollide(m_player);
	if (m_enemyManager->isNoEnemy()) {
		EndGame();
		unscheduleUpdate();
	}
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