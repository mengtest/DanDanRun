//
//  GameScene.cpp
//  DanDanRunning
//
//  Created by liuyuan on 14-8-30.
//
//

#include "GameScene.h"
#include "Cat.h"
#include "BeginPopLayer.h"
#include "OverPopLayer.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    //////////////////////////////////////////////////
    Sprite *Hbackground = Sprite::create("Hbackground.png");
    Hbackground->setPosition(320,568);
    addChild(Hbackground);
    
    Sprite *fangkuang = Sprite::create("fangkuang.png");
    fangkuang->setPosition(Vec2(320,visibleSize.height/2));
    addChild(fangkuang);
    //////////////////////////////////////////////////
    
    //  LayerColor* colorBackground = LayerColor::create(Color4B(200,190,180,80),640,640);
    //	colorBackground->setPosition(Vec2(0,(visibleSize.height-visibleSize.width)/2));
    //    addChild(colorBackground,0);
    
    cat=CatSprite::createCatSprite();
    addChild(cat);
    /////////////////////////////////////////////
    Sprite *title=Sprite::create("title.png");
    title->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height-title->getContentSize().height/2-10));
    addChild(title);
    /////////////////////////////////////////////
    
    schedule(schedule_selector(GameScene::myUpdate),1.0f/60.f);
    poplayer = BeginPopLayer::create(Color4B(0,0,0,180));
    addChild(poplayer);
    times=0;
    schedule(schedule_selector(GameScene::beginGame),1.f,4,0);
    //////////////////////////////////////////////
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    touchListener->setSwallowTouches(true);
    //////////////////////////////////////////////
    gametime=0;
    showTime=LabelTTF::create("0","Arial",40);
    showTime->setPosition(Vec2(240,40));
    addChild(showTime,1);
    
    LabelTTF *tip=LabelTTF::create("游戏记时：","Arial",40);
    tip->setPosition(Vec2(120,40));
    addChild(tip);
    
    //////////////////////////////////////////////
    
    return true;
}

void GameScene::gameTimeUp(float ft)
{
    gametime++;
    char timestring[4];
    sprintf(timestring,"%d",gametime);
    showTime->setString(timestring);
    log("%d",gametime);
}

void GameScene::beginGame(float ft)
{
    switch(times)
    {
        case 0:
        {
            poplayer->setNumber("2");
            times++;
            break;
        }
        case 1:
        {
            poplayer->setNumber("1");
            times++;
            break;
        }
        case 2:
        {
            runflag=true;
            removeChild(poplayer);
            times++;
            schedule(schedule_selector(GameScene::gameTimeUp),1.0f);
            break;
        }
        case 3:
        {
            times++;
            gameflag=true;
            break;
        }
        default:
            break;
            
            
    }
}



void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void GameScene::myUpdate(float ft)
{
    if(runflag&&!gameoverflag)
        cat->run();
    cat->speed=15+gametime/3;
}


bool GameScene::onTouchBegan(Touch* touch, Event *evet)
{
    //log("Enter the touch");
    return true;
}
void GameScene::onTouchMoved(Touch* touch, Event *event)
{
    if(gameflag&&!gameoverflag)
    {
        Point pos = touch->getLocation();
        float distance=(pos.x-cat->positionX)*(pos.x-cat->positionX)+(pos.y-cat->positionY)*(pos.y-cat->positionY);
      //  log("%f",distance);
        if(distance>10000)
        {
            gameoverflag=true;
            gameflag=false;
            runflag=false;
            log("**********gameover************");
            OverPopLayer *poplayer = OverPopLayer::create(Color4B(0,0,0,180));
            getParent()->addChild(poplayer);
            Director::getInstance()->pause();
            //addChild(overlayer);
        }
        
    }
}
void GameScene::onTouchEnded(Touch* touch, Event *event)
{
    log("Out the touch");
    if(gameflag)
    {
        gameoverflag=true;
        gameflag=false;
        runflag=false;
        log("**********gameover************");
        OverPopLayer *poplayer = OverPopLayer::create(Color4B(0,0,0,180));
        getParent()->addChild(poplayer);
        Director::getInstance()->pause();
    }
}