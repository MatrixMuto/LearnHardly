---
layout: post
title:  "什么东西"
date:   2015-1-1 18:02:32 +0000
categories: GameDev Cocos2d
---
Application的类结构

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();

    class  AppDelegate : private cocos2d::Application

    class CC_DLL Application : public ApplicationProtocol

    class CC_DLL ApplicationProtocol //接口定义

1.下载 Cocos2d-x 的SDK [Ver3.9链接 384MB](http://www.cocos2d-x.org/filedown/cocos2d-x-3.9.zip)
2.解压缩
3.Vs 2015编译项目，约30分钟
4.再把原先项目的代码Copy到对应目录

显示debug信息

    // turn on display FPS
    director->setDisplayStats(true);

改变window的大小

 #if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		glview->setFrameSize(designResolutionSize.width/2, designResolutionSize.height/2);
 #endif

窗口的设计大小

    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);

HelloScene的类结构

    class HelloWorld : public cocos2d::Layer
    class CC_DLL Layer : public Node
    class CC_DLL Node : public Ref

HelloScene的流程

    auto scene = HelloWorld::scene();

类静态方法

    Scene* HelloWorld::scene()
    {
        // 'scene' is an autorelease object
        auto scene = Scene::create();
        
	    // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
	    
	    // add layer as a child to scene
	    scene->addChild(layer);

	    // return the scene
        return scene;
    }
create方法是用一个宏生成的

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
宏如下

    #define CREATE_FUNC(__TYPE__) \
    static __TYPE__* create() \
    { \
        __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
        if (pRet && pRet->init()) \
        { \
            pRet->autorelease(); \
            return pRet; \
        } \
        else \
        { \
            delete pRet; \
            pRet = NULL; \
            return NULL; \
        } \
    }
    
让我手动宏替换看一下吧

    static HelloWorld* create() 
    { 
        HelloWorld *pRet = new(std::nothrow) HelloWorld(); 
        if (pRet && pRet->init()) 
        { 
            pRet->autorelease(); 
            return pRet; 
        } 
        else 
        { 
            delete pRet; 
            pRet = NULL; 
            return NULL; 
        } 
    }

> new(std::nothrow)是什么鬼语法。。？Google一下
>This constant value is used as an argument for operator new and operator new[] to indicate that these functions shall not throw an exception on failure, but return a null pointer instead.
> http://www.cplusplus.com/reference/new/nothrow/
> 失败了返回nullptr

这里走了三个函数，
1.构造函数
2.init函数
3.autorelease函数
挖掘一下autorelease函数，从类结构看，应该是Ref那里记成来的

    /**
     * Releases the ownership sometime soon automatically.
     *
     * This descrements the Ref's reference count at the end of current
     * autorelease pool block.
     *
     * If the reference count reaches 0 after the descrement, this Ref is
     * destructed.
     *
     * @returns The Ref itself.
     *
     * @see AutoreleasePool, retain, release
     * @js NA
     * @lua NA
     */
    Ref* autorelease();

接下来就是init函数了。

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

这个就先不管了，别忘了调用就行。

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

这两个size用来布局UI位置的，还要自己一个个算。。

    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    
    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));
这里有又有一个宏，用到c++11的语法。

    #define CC_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)

替换看看

    std::bind(&HelloWorld::menuCloseCallback, this, std::placeholders::_1)

> std::bind并看不懂，所以又Google了
> http://www.cplusplus.com/reference/functional/bind/
> std::bind的目的首先是返回一个函数指针（回调），然后，这个函数的一些参数是事先定好了的
> _1  _2代表了&HelloWorld::menuCloseCallback函数里参数的位置


create函数的声明是这样的

    MenuItemImage * MenuItemImage::create(const std::string& normalImage, const std::string& selectedImage, const ccMenuCallback& callback)

ccMenuCallback类型又是这样的

    typedef std::function<void(Ref*)> ccMenuCallback;

这信息量，我太low了

    void HelloWorld::menuCloseCallback(Ref* sender)
    {
        Director::getInstance()->end();
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
    #endif
    }

> 这意思就是MenuItemImage调出来的时候，不管你的参数是啥，反正 有sender  = this的意思？
> 这里只有debug看看地址了，并不相等。。
> sender的地址就是MenuItemImage这个对象的地址

**这里需要搞清楚sender，和定义时的this，是怎么搞上关系的。**

> 请看懂这个 C++11新的特性，
> http://en.cppreference.com/w/cpp/utility/functional/function
> 以前调用回调的时候，总是要把回调设计成静态函数，然后caller用的时候还要把receiver的地址传回来折腾。
> 这套手段，就可以把这套转换隐藏起来，来实现对象之间直接的回调的。
> Got it！
