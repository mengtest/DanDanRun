//
//  Dialog.h
//  DanDanRunning
//
//  Created by liuyuan on 14-8-31.
//
//

#ifndef __DanDanRunning__Dialog__
#define __DanDanRunning__Dialog__


#include "cocos2d.h"
using namespace cocos2d;

class Dialog : public cocos2d::Sprite
{
public:
    static Dialog* createDialog(std::string s);
    virtual bool init();
    CREATE_FUNC(Dialog);
    ~Dialog(){};
private:
    void initDialog(std::string s);
    std::string words;
    void myUpdate(float dt);
    int length;
    LabelBMFont *duiHua;
    std::string tmpwords;
};

#endif /* defined(__DanDanRunning__Dialog__) */
