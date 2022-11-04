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
	sceneWorld = nullptr;

	auto sampleTile = Sprite::create("sprite/ground/ground_top.png");
	float tileSizeWidth = sampleTile->getContentSize().width;
	float tileSizeHeight = sampleTile->getContentSize().height;
	
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 5, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 10, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 18, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 34, tileSizeHeight * 16)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 25, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 28, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 31, tileSizeHeight * 1)));
	m_enemyManager->AddEnemy(new Enemy(cocos2d::Vec2(tileSizeWidth * 8, tileSizeHeight * 8)));

	std::stringstream ss;
	ss << (m_player->getHP());
	auto hpText = Label::createWithTTF(ss.str(), "fonts/Marker Felt.ttf", 24);
	hpText->setPosition(m_mapManager->getPosition() + Vec2(640, 700));
	this->addChild(hpText, 2);

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
	if (m_player->isAttack()) {
		m_enemyManager->checkCollide(m_player);
	}
	m_mapManager->checkCollide(m_player);
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