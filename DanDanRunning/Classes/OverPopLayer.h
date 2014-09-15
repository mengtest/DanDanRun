//
//  OverPopLayer.h
//  MyGame
//
//  Created by liuyuan on 14-9-4.
//
//

#ifndef __MyGame__OverPopLayer__
#define __MyGame__OverPopLayer__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class OverPopLayer : public LayerColor
{
public:
    static OverPopLayer* create(const Color4B& color);
    
    virtual bool initWithColor(const Color4B& color);
    
    virtual bool onTouchBegan(Touch* touch, Event *evet);
    virtual void onTouchMoved(Touch* touch, Event *event);
    virtual void onTouchEnded(Touch* touch, Event *event);
private:
    void onRestart(Ref* pSender);
    void onExit(Ref* pSender);
};

#endif /* defined(__MyGame__OverPopLayer__) */
