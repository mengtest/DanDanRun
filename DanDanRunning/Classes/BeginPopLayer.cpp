//
//  BeginPopLayer.cpp
//  MyGame
//
//  Created by liuyuan on 14-9-3.
//
//

#include "BeginPopLayer.h"
#include "GameScene.h"
#include "cocos2d.h"



BeginPopLayer* BeginPopLayer::create(const Color4B& color)
{
    BeginPopLayer *pRet = new BeginPopLayer();
    if(pRet && pRet->initWithColor(color))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool BeginPopLayer::initWithColor(const cocos2d::Color4B &color)
{
    if (!LayerColor::initWithColor(color)) {
        return false;
    }
    

    
    
    //设置触摸事件监听
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(BeginPopLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(BeginPopLayer::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(BeginPopLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    touchListener->setSwallowTouches(true);
    
    daoshu = LabelTTF::create("3","Arial",40);
    daoshu->setPosition(Vec2(320,480));
    addChild(daoshu,2,900);
    
    //schedule(schedule_selector(BeginPopLayer::myUpdate),1.f,4,0.f);
    return true;
}
void BeginPopLayer::setNumber(const std::string &s)
{
    daoshu->setString(s);
}

/*
void BeginPopLayer::myUpdate(float fd)
{
    switch(times)
    {
        case 0:
        {
            times++;
            daoshu->setString("3");
            break;
        }
        case 1:
        {
            times++;
            daoshu->setString("2");
            break;
        }
        case 2:
        {
            times++;
            daoshu->setString("1");
            break;
        }
        case 3:
        {
            times++;
            log("ok");
           // Director::getInstance()->popScene();
            break;
        }
        default:
            break;
            
    }
    
}*/

bool BeginPopLayer::onTouchBegan(Touch* touch, Event *evet)
{
    return false;
}

void BeginPopLayer::onTouchMoved(Touch* touch, Event *event)
{
    
}
void BeginPopLayer::onTouchEnded(Touch* touch, Event *event)
{
    
}