//
//  GameHelp.cpp
//  DanDanRunning
//
//  Created by liuyuan on 14-8-30.
//
//
#include "GameHelp.h"
#include "Dialog.h"
#include "Dialog2.h"
#include <unistd.h>
#include "HelloWorldScene.h"


USING_NS_CC;
int times;

bool GameHelp::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    

    
    auto labelBack = LabelTTF::create("点击返回", "Arial", 40);
    auto itemBack = MenuItemLabel::create(labelBack, CC_CALLBACK_1(GameHelp::menuBackToMain, this));
    itemBack->setPosition(Point(visibleSize.width, 0));
    itemBack->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
    
    auto menu = Menu::create(itemBack, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu,1);
    

////////////////////////////
    Sprite *Hbackground = Sprite::create("Hbackground.png");
    Hbackground->setPosition(320,568);
    addChild(Hbackground);
    times=1;
    schedule(schedule_selector(GameHelp::myUpdate),3.f,4,0);
////////////////////////////
    return true;
}

Scene* GameHelp::createScene()
{
    auto scene = Scene::create();
    auto layer = GameHelp::create();
    scene->addChild(layer);
    return scene;
}

void GameHelp::menuBackToMain( cocos2d::Ref* pSender )
{
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void GameHelp::myUpdate(float dt)
{
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    switch(times)
    {
        case 1:
        {
            Dialog* item1 = Dialog::createDialog("人来了！\n快跑啊！");
            addChild(item1);
            times++;
            break;
        }
        case 2:
        {
            Dialog2* item2 = Dialog2::createDialog("怕P啊！\n不就是人嘛~");
            addChild(item2);
            times++;
            break;
        }
        case 3:
        {
            Dialog* item3 = Dialog::createDialog("是专捏猫\n蛋蛋的人类！");
            item3->setPosition(origin.x,origin.y-380);
            addChild(item3);
            times++;
            break;
        }
        case 4:
        {
            Sprite *dandan = Sprite::create("dandan.png");
            dandan->setPosition(Vec2(320,320));
            addChild(dandan);
            times++;
            
        }
        default:
            break;
    }
}