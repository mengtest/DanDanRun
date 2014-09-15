//
//  OverPopLayer.cpp
//  MyGame
//
//  Created by liuyuan on 14-9-4.
//
//

#include "OverPopLayer.h"
#include "HelloWorldScene.h"
#include "GameScene.h"
#include "cocos2d.h"



OverPopLayer* OverPopLayer::create(const Color4B& color)
{
    OverPopLayer *pRet = new OverPopLayer();
    if(pRet && pRet->initWithColor(color))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool OverPopLayer::initWithColor(const cocos2d::Color4B &color)
{
    if (!LayerColor::initWithColor(color)) {
        return false;
    }
    
    
    
    
    auto banner = LabelTTF::create("游戏结束","Arial",60);
    banner->setPosition(Vec2(320,480+130));
    addChild(banner);
    
    
    
    Size winSize = Director::getInstance()->getWinSize();
    Point centerPos = Point(winSize.width / 2, winSize.height / 2-100);
    
    MenuItemFont::setFontName("Consolas");
    MenuItemFont::setFontSize(80);
    

    auto menuItemRestart = MenuItemFont::create("RESTART", CC_CALLBACK_1(OverPopLayer::onRestart, this));
    auto menuItemExit = MenuItemFont::create("EXIT", CC_CALLBACK_1(OverPopLayer::onExit, this));
    
    
    auto menu = Menu::create(menuItemRestart, menuItemExit, NULL);
    menu->alignItemsVertically();
    addChild(menu);
    menu->setPosition(centerPos);
    
    
    
    
    
    
    //设置触摸事件监听
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(OverPopLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(OverPopLayer::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(OverPopLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    touchListener->setSwallowTouches(true);
    

    

    return true;
}



bool OverPopLayer::onTouchBegan(Touch* touch, Event *evet)
{
    return true;
}

void OverPopLayer::onTouchMoved(Touch* touch, Event *event)
{
    
}
void OverPopLayer::onTouchEnded(Touch* touch, Event *event)
{
    
}

void OverPopLayer::onRestart(Ref* pSender)
{
    
    Director::getInstance()->replaceScene(GameScene::createScene());
    Director::getInstance()->resume();

}

void OverPopLayer::onExit(Ref* pSender)
{
/*
 #if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
*/
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    Director::getInstance()->resume();
}