#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    


    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update(float dt) override;

private:

	Player* _player;

	void initKeyboard();
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

};

#endif // __HELLOWORLD_SCENE_H__
