//
//  Cat.cpp
//  MyGame
//
//  Created by liuyuan on 14-9-2.
//
//

#include "Cat.h"
#include "cocos2d.h"
#include "math.h"

using namespace cocos2d;

CatSprite* CatSprite::createCatSprite()
{
    CatSprite *cat=new CatSprite();
    if(cat && cat->init())
    {
        cat->autorelease();
        cat->initCat();
        return cat;
    }
    CC_SAFE_DELETE(cat);
    return NULL;
}

bool CatSprite::init()
{
    if(!Sprite::init())
    {
        return false;
    }
    return true;
}

void CatSprite::initCat()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    runDirection=0;
    positionX=origin.x+visibleSize.width/2;
    positionY=origin.y+visibleSize.height/2;
    
    picture = Sprite::create("maomi.png");
    picture->setPosition(Vec2(positionX,positionY));
    picture->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(picture);
    
    
    particleSyetemFree = ParticleSun::create();
    //设置贴图
    particleSyetemFree->setTexture( CCTextureCache::sharedTextureCache()->addImage("snow.png"));
    //设置自动释放
    particleSyetemFree->setAutoRemoveOnFinish(true);
    //设置移动类型 kCCPositionTypeFree
    particleSyetemFree->setPositionType(ParticleSystem::PositionType::FREE);
    particleSyetemFree->setPosition(Vec2(positionX-30*cos(runDirection*3.14/180),positionY-30*sin(runDirection*3.14/180)));
   
    this->addChild(particleSyetemFree);
}

void CatSprite::run()
{
    positionX+=speed*cos(runDirection*3.14/180);
    positionY+=speed*sin(runDirection*3.14/180);
    picture->setPosition(Vec2(positionX,positionY));
    particleSyetemFree->setPosition(Vec2(positionX-30*cos(runDirection*3.14/180),positionY-30*sin(runDirection*3.14/180)));
    
    if(positionX<10)
    {
        runDirection=CCRANDOM_0_1() * 90-45;
        ActionInterval* rotateTo = RotateTo::create(.2f, -runDirection);
        picture->runAction(rotateTo);
    }
    else if(positionX>630)
    {
        runDirection=CCRANDOM_0_1() *90+135;
        ActionInterval* rotateTo = RotateTo::create(.2f, -runDirection);
        picture->runAction(rotateTo);
    }
    else if(positionY<15+((visibleSize.height-visibleSize.width))/2)
    {
        runDirection=CCRANDOM_0_1() *90+45;
        ActionInterval* rotateTo = RotateTo::create(.2f, -runDirection);
        picture->runAction(rotateTo);
    }
    else if(positionY>((visibleSize.height+visibleSize.width)/2-15))
    {
        runDirection=CCRANDOM_0_1() *90+225;
        ActionInterval* rotateTo = RotateTo::create(.2f, -runDirection);
        picture->runAction(rotateTo);
    }
    
}

