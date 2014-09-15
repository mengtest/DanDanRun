#include "HelloWorldScene.h"
#include "GameScene.h"
#include "GameHelp.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
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

    // add a label shows "Hello World"
    // create and initialize a label
    
 
    auto labelStart = LabelTTF::create("开始游戏","Arial",48);
    auto labelHelp = LabelTTF::create("游戏帮助","Arial",48);
    auto labelAbout = LabelTTF::create("退出游戏","Arial",48);
    
    auto startItem = MenuItemLabel::create(labelStart,CC_CALLBACK_1(HelloWorld::menuCallback, this));
    startItem->setTag(START);
    startItem->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.5+50));
    
    auto helpItem = MenuItemLabel::create(labelHelp,CC_CALLBACK_1(HelloWorld::menuCallback,this));
    helpItem->setTag(HELP);
    helpItem->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.5-50));
    
    auto aboutItem = MenuItemLabel::create(labelAbout,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    aboutItem->setTag(ABOUT);
    aboutItem->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.5-150));
    
    
    auto mainMenu = Menu::create(startItem, helpItem, aboutItem, NULL);
    mainMenu->setPosition(origin);
    this->addChild(mainMenu,1);
    
 
//    Sprite *background=Sprite::create("background2.png");
//    background->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.5));
//    background->setScale(visibleSize.height/960);
//    addChild(background,0);
    Sprite *Hbackground = Sprite::create("Hbackground.png");
    Hbackground->setPosition(320,568);
    addChild(Hbackground);
    
    
    
//   auto *title=LabelTTF::create("蛋蛋快跑","Arial",60);
//   title->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height-title->getContentSize().height/2-180));
//    addChild(title,1);
    
        
    Sprite *title=Sprite::create("title.png");
    title->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height-title->getContentSize().height/2-140));
    addChild(title);
        
    
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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

void HelloWorld::menuCallback(cocos2d::Ref* pSender)
{
    switch(((Node*)pSender)->getTag())
    {
        case START:
            log("go to game");
            Director::getInstance()->replaceScene(GameScene::createScene());
            break;
        case HELP:
            log("go to help");
            Director::getInstance()->replaceScene(GameHelp::createScene());
            break;
        default:
            break;
    }
}
