//
//  Dialog2.cpp
//  MyGame
//
//  Created by liuyuan on 14-8-31.
//
//

#include "Dialog2.h"
Dialog2* Dialog2::createDialog(std::string s)
{
    Dialog2 *dialog = new Dialog2();
    if (dialog && dialog->init())
    {
        dialog->autorelease();
        dialog->initDialog(s);
        return dialog;
    }
    CC_SAFE_DELETE(dialog);
    
    return NULL;
}

bool Dialog2::init()
{
    if (!Sprite::init())
	{
		return false;
	}
    
	return true;
}

void Dialog2::initDialog(std::string st)
{
    words=st;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *background = Sprite::create("duihua2.png");
    background->setPosition(Vec2(visibleSize.width*0.35,visibleSize.height-background->getContentSize().height-20));
    this->addChild(background,1);
    
    Sprite *guapi =Sprite::create("guapi2.png");
    guapi->setPosition(Vec2(guapi->getContentSize().width/2,visibleSize.height-450));
    addChild(guapi);
    std::string s;
    length=0;
    duiHua = LabelBMFont::create(s,"dandan.fnt");
    duiHua->setAnchorPoint(Vec2(0,1));
    duiHua->setColor(Color3B::BLACK);
    duiHua->setPosition(Vec2(background->getPosition().x-95,background->getPosition().y+70));
    addChild(duiHua,1,900);
    
    schedule(schedule_selector(Dialog2::myUpdate),0.2f,words.length(),0);
    
    
    
}
void Dialog2::myUpdate(float dt)
{
    if(length<words.length())
        length+=3;
    if(length==6) length=4;
    if(length==13) length=11;
    tmpwords=words.substr(0,length);
    LabelBMFont *tmpitem=(LabelBMFont*)this->getChildByTag(900);
    tmpitem->setString(tmpwords);
    
}
