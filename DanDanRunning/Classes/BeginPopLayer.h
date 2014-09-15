//
//  BeginPopLayer.h
//  MyGame
//
//  Created by liuyuan on 14-9-3.
//
//

#ifndef __MyGame__BeginPopLayer__
#define __MyGame__BeginPopLayer__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class BeginPopLayer : public LayerColor
{
public:
    static BeginPopLayer* create(const Color4B& color);
    
    virtual bool initWithColor(const Color4B& color);
    
    virtual bool onTouchBegan(Touch* touch, Event *evet);
    virtual void onTouchMoved(Touch* touch, Event *event);
    virtual void onTouchEnded(Touch* touch, Event *event);
    void setNumber(const std::string &s);
    
private:
    LabelTTF* daoshu;
//    void myUpdate(float fd);
    
    
};

#endif /* defined(__MyGame__BeginPopLayer__) */
