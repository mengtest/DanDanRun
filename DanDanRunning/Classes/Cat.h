//
//  Cat.h
//  MyGame
//
//  Created by liuyuan on 14-9-2.
//
//

#ifndef __MyGame__Cat__
#define __MyGame__Cat__

#include "cocos2d.h"

class CatSprite : public cocos2d::Sprite
{
public:
    static CatSprite* createCatSprite();
    virtual bool init();
    CREATE_FUNC(CatSprite);
    ~CatSprite(){};
    void run();
    float positionX;
    float positionY;
    int speed=15;
private:
    void initCat();
    int runDirection;
    cocos2d::Size visibleSize;

    Sprite *picture;
    cocos2d::ParticleSystem* particleSyetemFree;
    
};


#endif /* defined(__MyGame__Cat__) */
