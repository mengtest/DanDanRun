//
//  GameHelp.h
//  DanDanRunning
//
//  Created by liuyuan on 14-8-30.
//
//

#ifndef __DanDanRunning__GameHelp__
#define __DanDanRunning__GameHelp__

#include <iostream>
#include "cocos2d.h"

class GameHelp : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuBackToMain(cocos2d::Ref* pSender);
    void myUpdate(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameHelp);
};

#endif /* defined(__DanDanRunning__GameHelp__) */
