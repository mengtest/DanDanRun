//
//  GameScene.h
//  DanDanRunning
//
//  Created by liuyuan on 14-8-30.
//
//

#ifndef __DanDanRunning__GameScene__
#define __DanDanRunning__GameScene__

#include "cocos2d.h"
#include "Cat.h"
#include "BeginPopLayer.h"
#include "OverPopLayer.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    void myUpdate(float ft);
    void beginGame(float ft);
    void gameTimeUp(float ft);
    virtual bool onTouchBegan(Touch* touch, Event *evet);
    virtual void onTouchMoved(Touch* touch, Event *event);
    virtual void onTouchEnded(Touch* touch, Event *event);
    
private:
    CatSprite *cat;
    bool runflag=false;
    bool gameflag=false;
    bool gameoverflag=false;
    int times;
    int gametime=0;
    BeginPopLayer *poplayer;
    LabelTTF *showTime;
    
};


#endif /* defined(__DanDanRunning__GameScene__) */
