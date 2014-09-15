//
//  Dialog2.h
//  MyGame
//
//  Created by liuyuan on 14-8-31.
//
//

#ifndef __MyGame__Dialog2__
#define __MyGame__Dialog2__
#include "cocos2d.h"
using namespace cocos2d;

class Dialog2 : public cocos2d::Sprite
{
public:
    static Dialog2* createDialog(std::string s);
    virtual bool init();
    CREATE_FUNC(Dialog2);
    ~Dialog2(){};
private:
    void myUpdate(float dt);
    void initDialog(std::string s);
    std::string words;
    int length;
    LabelBMFont *duiHua;
    std::string tmpwords;
};


#endif /* defined(__MyGame__Dialog2__) */
