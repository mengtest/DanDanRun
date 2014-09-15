//
//  Dialog.cpp
//  DanDanRunning
//
//  Created by liuyuan on 14-8-31.
//
//

#include "Dialog.h"
#include "cocos2d.h"
using namespace cocos2d;


Dialog* Dialog::createDialog(std::string s)
{
    Dialog *dialog = new Dialog();
    if (dialog && dialog->init())
    {
        dialog->autorelease();
        dialog->initDialog(s);
        return dialog;
    }
    CC_SAFE_DELETE(dialog);
    
    return NULL;
}

bool Dialog::init()
{
    if (!Sprite::init())
	{
		return false;
	}
    
	return true;
}

void Dialog::initDialog(std::string st)
{
    words=st;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *background = Sprite::create("duihua.png");
    background->setPosition(Vec2(visibleSize.width*0.65,visibleSize.height-background->getContentSize().height/2+20));
    this->addChild(background,1);
    
    Sprite *guapi =Sprite::create("guapi1.png");
    guapi->setPosition(Vec2(visibleSize.width-guapi->getContentSize().width/2,visibleSize.height-background->getContentSize().height+20));
    addChild(guapi);
    std::string s=" ";
    length=0;
    duiHua = LabelBMFont::create(s,"dandan.fnt");
    duiHua->setColor(Color3B::BLACK);
    duiHua->setAnchorPoint(Vec2(0,1));
    duiHua->setPosition(Vec2(background->getPosition().x-100,background->getPosition().y+70));
    addChild(duiHua,1,900);
    
    schedule(schedule_selector(Dialog::myUpdate),0.2f,words.length(),0);

    

    
    
}
void Dialog::myUpdate(float dt)
{
    if(length<words.length())
        length+=3;
    if(length==15) length=13;
    tmpwords=words.substr(0,length);
    LabelBMFont *tmpitem=(LabelBMFont*)this->getChildByTag(900);
    tmpitem->setString(tmpwords);
    
}
