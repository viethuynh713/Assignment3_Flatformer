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
	//this->addChild(m_player->getHPText(), 2);
	//this->addChild(m_player->getCoinText(), 2);
	//this->addChild(m_player->getStarText(), 2);

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
    state = INIT;
    SetUi();
	//Play();
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
    state = PLAYING;
    //m_player = new Player();
    //this->m_mapManager->addChild(m_player, 1);
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
    endgamePnl->setVisible(true);
    playingPnl->setVisible(false);

    state = END;
}

void GameController::Restart()
{
    //m_player = new Player();
    state = PLAYING;
}

void GameController::Pause()
{
    state = PAUSE;
}
void GameController::Resume()
{
    state = PLAYING;
}
void GameController::setPhysicsWorld(cocos2d::PhysicsWorld* world) {
	sceneWorld = world;
}
void GameController::SetUi()
{
    //////////////////////////////
    //                          //
    //      Menu UI             //
    //                          //
    //////////////////////////////
    // Backgorund
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    background = Sprite::create("UI/Background.png");
    auto z = background->getContentSize();
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0, 0));
    addChild(background);


    menuInit = Sprite::create();
    menuInit->setPosition(Vec2(0, 0));
    background->addChild(menuInit);


    // About us Button
    auto aboutUsBtn = ui::Button::create("/UI/AboutUsBtn.png");
    aboutUsBtn->setAnchorPoint(Vec2(1, 0));
    aboutUsBtn->setPosition(Vec2(visibleSize.width - 15, 15));
    aboutUsBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            //CCLOG("AboutUS");

        }
        });
    menuInit->addChild(aboutUsBtn);

    // Play Button
    auto playBtn = ui::Button::create("/UI/PlayBtn.png");
    playBtn->setAnchorPoint(Vec2(0.5, 0.5));
    playBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3));
    playBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            background->setVisible(false);
            playingPnl->setVisible(true);
            Play();
            //CCLOG("Play");

        }
        });

    menuInit->addChild(playBtn);

    // Option Button
    auto optionBtn = ui::Button::create("/UI/OptionBtn.png");
    optionBtn->setAnchorPoint(Vec2(0.5, 0.5));
    optionBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3 - 80));
    optionBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            menuInit->setVisible(false);
            optionPnl->setVisible(true);
            //CCLOG("Option");

        }
        });
    menuInit->addChild(optionBtn);

    // Quit Button
    auto quitBtn = ui::Button::create("/UI/QuitBtn.png");
    quitBtn->setAnchorPoint(Vec2(0.5, 0.5));
    quitBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3 - 160));
    quitBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            //CCLOG("Quit");
            Director::getInstance()->end();
        }
        });
    menuInit->addChild(quitBtn);

    // Option Panel
    optionPnl = Sprite::create("UI/EngamePnl.png");
    optionPnl->setVisible(false);
    optionPnl->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
    background->addChild(optionPnl);

    auto closeBtn = ui::Button::create("UI/Icon/close 1.png");

    closeBtn->setPosition(Vec2(250, 120));
    closeBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            menuInit->setVisible(true);
            optionPnl->setVisible(false);
            //CCLOG("close option");

        }
        });

    volume = ui::Button::create("UI/Icon/volume (1) 1.png");
    volume->setPosition(optionPnl->getContentSize() / 2);
    volume->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            SetVolume(false);
            //CCLOG("mute");

        }
        });


    muteVolume = ui::Button::create("UI/Icon/MuteIcon.png");
    muteVolume->setPosition(optionPnl->getContentSize() / 2);
    muteVolume->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            SetVolume(true);
            //CCLOG("no mute");

        }
        });



    optionPnl->addChild(closeBtn);
    optionPnl->addChild(volume);
    optionPnl->addChild(muteVolume);


    //////////////////////////////
    //                          //
    //      Playing  UI         //
    //                          //
    //////////////////////////////
    playingPnl = Sprite::create();
    playingPnl->setPosition(Vec2(0, 0));
    playingPnl->setVisible(false);
    addChild(playingPnl);
    /*auto heart0 = Sprite::create("UI/Icon/heart (1) 1.png");
    heart0->setAnchorPoint(Vec2(0, 0));
    heart0->setPosition(Vec2(15, visibleSize.height - 60));
    playingPnl->addChild(heart0);

    auto heart1 = Sprite::create("UI/Icon/heart (1) 1.png");
    heart1->setAnchorPoint(Vec2(0, 0));
    heart1->setPosition(Vec2(65, visibleSize.height - 60));
    playingPnl->addChild(heart1);

    auto heart2 = Sprite::create("UI/Icon/heart (1) 1.png");
    heart2->setAnchorPoint(Vec2(0, 0));
    heart2->setPosition(Vec2(115, visibleSize.height - 60));
    playingPnl->addChild(heart2);*/

    // Setting Button
    playingPnl->addChild(m_player->getHPText(), 2);
    playingPnl->addChild(m_player->getCoinText(), 2);
    playingPnl->addChild(m_player->getStarText(), 2);
    auto settingBtn = ui::Button::create("UI/SettingBtn.png");
    settingBtn->setAnchorPoint(Vec2(1, 1));
    settingBtn->setPosition(visibleSize);
    settingBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            settingPnl->setVisible(true);
            Pause();
            //CCLOG("open panel setting");

        }
        });
    playingPnl->addChild(settingBtn);
    //Setting panel

    settingPnl = Sprite::create("UI/SettingTemplate.png");
    settingPnl->setPosition(visibleSize / 2);
    settingPnl->setVisible(false);
    playingPnl->addChild(settingPnl);

    //Setting panel -> Resume Button
    auto settingPnlSize = settingPnl->getContentSize();
    auto resumeBtn = ui::Button::create("UI/resumeBtn.png");
    resumeBtn->setPosition(Vec2(settingPnlSize.width / 2, settingPnlSize.height - 50));
    resumeBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            settingPnl->setVisible(false);
            Resume();
            //Resume game


        }
        });
    settingPnl->addChild(resumeBtn);


    //Setting panel -> new game Button
    auto newGameBtn = ui::Button::create("UI/newGameBtn.png");
    newGameBtn->setPosition(Vec2(settingPnlSize.width / 2, settingPnlSize.height - 125));
    newGameBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            settingPnl->setVisible(false);
            Restart();
            //CCLOG("new");

        }
        });
    settingPnl->addChild(newGameBtn);


    //Setting panel -> home
    auto homeBtn = ui::Button::create("UI/HomeBtn.png");
    homeBtn->setPosition(Vec2(settingPnlSize.width / 2, settingPnlSize.height - 200));
    homeBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {

            settingPnl->setVisible(false);
            playingPnl->setVisible(false);
            background->setVisible(true);
            //Pause();
            //CCLOG("home");

        }
        });
    settingPnl->addChild(homeBtn);


    volumePlaying = ui::Button::create("UI/Icon/volume (1) 1.png");
    volumePlaying->setPosition(Vec2(settingPnlSize.width / 2, 50));
    volumePlaying->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            SetVolume(false);
            //CCLOG("mute");

        }
        });
    settingPnl->addChild(volumePlaying);

    muteVolumePlaying = ui::Button::create("UI/Icon/MuteIcon.png");
    muteVolumePlaying->setPosition(Vec2(settingPnlSize.width / 2, 50));
    muteVolumePlaying->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            SetVolume(true);
            //CCLOG("no mute");

        }
        });
    settingPnl->addChild(muteVolumePlaying);
    SetVolume(true);

    //////////////////////////////
    //                          //
    //      EndGame UI          //
    //                          //
    //////////////////////////////


    endgamePnl = Sprite::create("UI/EngamePnl.png");
    endgamePnl->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
    endgamePnl->setVisible(false);
    auto endSize = endgamePnl->getContentSize();
    addChild(endgamePnl);


    auto title = Sprite::create("UI/cooltext422414789638015 1.png");
    title->setPosition(Vec2(endSize.width / 2, endSize.height + 100));
    endgamePnl->addChild(title);

    auto restartBtn = ui::Button::create("UI/resumeBtn.png");
    restartBtn->setPosition(Vec2(endSize.width / 2, endSize.height / 2 + 18));
    restartBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {

            endgamePnl->setVisible(false);
            playingPnl->setVisible(true);
            Restart();

        }
        });
    endgamePnl->addChild(restartBtn);

    auto homeEndBtn = ui::Button::create("UI/resumeBtn.png");
    homeEndBtn->setPosition(Vec2(endSize.width / 2, endSize.height / 2 - 18));
    homeEndBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED)
        {

            background->setVisible(true);
            endgamePnl->setVisible(false);
            playingPnl->setVisible(false);
            Pause();

        }
        });
    endgamePnl->addChild(homeEndBtn);
}

void GameController::SetVolume(bool isNewVolume)
{
    m_isVolume = isNewVolume;
    if (m_isVolume)
    {
        volumePlaying->setVisible(true);
        muteVolumePlaying->setVisible(false);
        volume->setVisible(true);
        muteVolume->setVisible(false);
    }
    else
    {
        muteVolumePlaying->setVisible(true);
        volumePlaying->setVisible(false);
        muteVolume->setVisible(true);
        volume->setVisible(false);
    }

}

ItemManager* GameController::getItemManager() {
	return m_itemManager;
}