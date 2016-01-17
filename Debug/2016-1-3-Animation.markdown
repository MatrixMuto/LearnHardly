---
layout: post
title:  "Cocos2d Animation 2"
date:   2015-1-3 18:02:32 +0000
categories: cocos2d
---
Dash Quest第一个界面有个小朋友跑步的动画，
Google一下，可以用Cocos2d的序列帧动画来实现，
找个Sample来试一下吧
cpp-tests里找到一个

Cocos2d上面有这么个[文档][cocos2d-animation]



{% highlight c++ %}
    //
    // Manual animation
    //
    auto animation = Animation::create();
    for( int i=1;i<15;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "Images/grossini_dance_%02d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    // should last 2.8 seconds. And there are 14 frames.
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);

    auto action = Animate::create(animation);
    _grossini->runAction(Sequence::create(action, action->reverse(), nullptr));
{% endhighlight %}

Animation的文件位置：
cocos2d-x-3.8.1\cocos\2d\CCAnimation.cpp

addSpriteFrameWithFile

setDelayPerUnit

setRestoreOriginalFrame
这里需要一张相关的类结构图。

Animate
Sequence::create(action, action->reverse(), nullptr)

_grossini是onEnter
{% highlight c++ %}
    _grossini = Sprite::create(s_pathGrossini);
    _grossini->retain();
{% endhighlight %}

看了一会代码，再看一眼文档，文档和代码才被融汇了。。

>Cocos2d-x中，动画的具体内容是依靠精灵显示出来的，
>为了显示动态图片，我们需要不停切换精灵显示的内容，通过把静态的精灵变为动画播放器从而实现动画效果。
>动画由帧组成，每一帧都是一个纹理，我们可以使用一个纹理序列来创建动画。
>我们使用Animation类描述一个动画，而精灵显示动画的动作则是一个Animate对象。
>动画动作Animate是精灵显示动画的动作，它由一个动画对象创建，并由精灵执行。


所以序列帧动画，就看http://www.cocos2d-x.org/docs/manual/framework/native/v3/frame-animation/zh
里面plist怎么来生成呢。

>Tools for creating Sprite Sheets
>Creating a sprite sheet manually is a tedious process. 
>Fortunately there are tools that can generate them automatically. 
>These tools can provide even more ways to adjust your sprite sheet for maximum optimization!
Here are a few tools:

Cocos Studio
ShoeBox
Texture Packer
Zwoptex


Polygon Sprite
AutoPolygon


[Jekyll docs][jekyll-docs]

[jekyll-docs]: http://jekyllrb.com/docs/home
[cocos2d-animation]: http://www.cocos2d-x.org/docs/manual/framework/native/v3/frame-animation/zh
