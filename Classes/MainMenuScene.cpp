#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGroundSprite = Sprite::create("background.png");
	backGroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backGroundSprite);

	auto titleSprite = Sprite::create("Title.png");
	titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));
	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create("Play Button.png", "Play Button Clicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	
    return true;
}


void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender) {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}