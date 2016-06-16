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

###搞搞gdb
gdb需要symbol???
* file ffplay_g
* set args <arg>
* run
* s
* n
* b <func name>
* c
```
(gdb) i s
#0  rtmp_open (s=0x7fffe8005760, uri=0x7fffe80057b8 "rtmp://localhost:1935/vod/test.flv", flags=1)
    at libavformat/rtmpproto.c:2579
#1  0x00000000006aee06 in ffurl_connect (uc=0x7fffe8005760, options=options@entry=0x7fffec989d20)
    at libavformat/avio.c:209
#2  0x00000000006af4ca in ffurl_open_whitelist (puc=puc@entry=0x7fffec989c88, 
    filename=<optimized out>, flags=<optimized out>, int_cb=<optimized out>, options=0x7fffec989d20, 
    whitelist=0x0, blacklist=blacklist@entry=0x0, parent=parent@entry=0x0) at libavformat/avio.c:347
#3  0x000000000058be20 in ffio_open_whitelist (s=0x7fffe80008e0, filename=<optimized out>, 
    flags=<optimized out>, int_cb=<optimized out>, options=<optimized out>, 
    whitelist=<optimized out>, blacklist=0x0) at libavformat/aviobuf.c:992
#4  0x00000000006355a5 in io_open_default (s=<optimized out>, pb=<optimized out>, 
    url=<optimized out>, flags=<optimized out>, options=<optimized out>) at libavformat/options.c:112
#5  0x0000000000691bd3 in init_input (options=0x7fffec989d20, 
    filename=0x1cd0fd0 "rtmp://localhost:1935/vod/test.flv", s=0x7fffe80008c0)
    at libavformat/utils.c:383
#6  avformat_open_input (ps=ps@entry=0x7fffec989db0, 
    filename=0x1cd0fd0 "rtmp://localhost:1935/vod/test.flv", fmt=<optimized out>, 
    options=0x1b6dc48 <format_opts>) at libavformat/utils.c:497
#7  0x000000000048a283 in read_thread (arg=0x7ffff7ec2040) at ffplay.c:2873
#8  0x00007ffff6e23ad8 in ?? () from /usr/lib/x86_64-linux-gnu/libSDL-1.2.so.0
#9  0x00007ffff6e63109 in ?? () from /usr/lib/x86_64-linux-gnu/libSDL-1.2.so.0
#10 0x00007ffff64cc182 in start_thread (arg=0x7fffec98a700) at pthread_create.c:312
#11 0x00007ffff61f947d in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:111
```

###RTMFP是什么..
* [Real Time Media Flow Protocol](https://en.wikipedia.org/wiki/Real_Time_Media_Flow_Protocol)
  UDP,P2P

###调试代码比只看代码效果要好一点.

###ijkplayer怎么用上ffmpeg的?


<<<<<<< HEAD
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

=======
###项目构建工具
* nginx有一套auto脚本,用来生成Makefile
* ffmpeg有一个configure生成config.h,Makefile会依赖这个来编译
* webrtc又有一套ninja编译系统
* ndk用一套Android.mk和Application.mk
* android studio又用一套gradle来管理项目
* 我用什么呢...只会手写简单的Makefile~~~
* 所以IDE的好处``` 
>>>>>>> 129a1bb969cbaa7fddca0b7b43046d28d581da99
