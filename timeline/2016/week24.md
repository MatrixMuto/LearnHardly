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


###-Wimplicit-function-declaration



