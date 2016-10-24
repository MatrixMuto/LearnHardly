*Week 24	June 13, 2016	June 19, 2016*

###Intellij IDEA 怎么当ffmpeg的IDE呢?
  * 代码跳转
  * 编译
  * 单步调试
  * 必然会需要安装插件什么的...上次装过什么..没成功.
  * 怎么在Project里不像是.o文件


###两感叹号干嘛的?
```
foo = !!(bar);
```

###RTMFP是什么..
* [Real Time Media Flow Protocol](https://en.wikipedia.org/wiki/Real_Time_Media_Flow_Protocol)
  UDP,P2P

###调试代码比只看代码效果要好一点.

###ijkplayer怎么用上ffmpeg的?

###Android Studio Open 一个项目目录的之后,按什么顺序做了哪些事情?
*因为这个过程太久了,又不能Cancel重来*


###intprt_t,怎么include头文件
```
#include <stdint.h>  //简直要命啊
```
在*#include <netinet/in.h>*中会 *#include< stdint.h>*

###cc gcc g++有什么区别?
http://stackoverflow.com/a/1516658
在Ubuntu 14.04默认配置上,
cc->/usr/bin/cc->/etc/alternatives/cc->/usr/bin/gcc


###-Wimplicit-function-declaration是什么warning?
[StackOverflow](http://stackoverflow.com/a/9182835)
意思是,你用了一个没有声明过的函数,gcc会假设这个函数的声明是int func(),
链接的时候能成功,因为你在别的.c里找到了..
如果你返回的是是指针类型,但指针类型比int的size大的时候,就会引起问题了.

C99和C11已经定义这中问题应当被当成error,但是gcc的实现还是把它当做warning.(也许是出于兼容行的考虑)

###android lua项目
挺有意思吧


###要不做一个Android手机屏幕直播软件,用上阿里云/腾讯云的直播SDK,理论上斗鱼/熊猫等等应该能支持手游直播了吧?
* 通过手机,分享*前/后置摄像头+麦克风*,*手机屏幕+麦克风(中放大游戏声音)*,支持你购买的VPS,私密链接.


###UIAnimatorview
View的*text*,*resource-id*,怎么用Java代码设置.
* resource-id
> 如果在values/ids.xml里定义的话,uiautomatorviewer是可以看到的
* text
> 不知道怎么设置
* content-desc
> 从View就有这个方法来设置

###gcc,arm-xxx-gcc,
默认会Link哪些库?
为什么epoll都能link过?
libc有哪些东西?
[libc.so](http://stackoverflow.com/questions/6969225/libraries-that-are-linked-by-default)

###项目构建工具
* nginx有一套auto脚本,用来生成Makefile
* ffmpeg有一个configure生成config.h,Makefile会依赖这个来编译
* webrtc又有一套ninja编译系统
* ndk用一套Android.mk和Application.mk
* android studio又用一套gradle来管理项目
* 我用什么呢...只会手写简单的Makefile~~~
* 所以IDE的好处``` 
