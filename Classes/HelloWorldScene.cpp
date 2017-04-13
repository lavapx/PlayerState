#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

	Director::getInstance()->setDisplayStats(false);
  
    _player = Player::create("TestCube.png");

	_player->setAnchorPoint(Vec2::ZERO);
    _player->setPosition(Vec2(visibleSize.width/2 + origin.x, _player->getContentSize().height * 2));

    this->addChild(_player, 0);

	this->initKeyboard();

	this->scheduleUpdate();
    
    return true;
}


void HelloWorld::initKeyboard()
{
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
	
	switch (key)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_player->input(Input::LEFT_PRESS);
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_player->input(Input::RIGHT_PRESS);
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		_player->input(Input::JUMP_PRESS);
		break;

	default:
		break;
	}

}

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {

	
	switch (key)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_player->input(Input::LEFT_RELEASE);
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_player->input(Input::RIGHT_RELEASE);
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		_player->input(Input::JUMP_RELEASE);
		break;
	default:
		
		break;
	}

}

void HelloWorld::menuCloseCallback(Ref* pSender)
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

void HelloWorld::update(float dt)
{
	_player->update(dt);

}
