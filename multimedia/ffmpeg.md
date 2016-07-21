##如何进行configure
  1. 为什么没有ffplay?
  
##看ffmpeg代码?

###FFmpeg Basics
[Book link](http://ffmpeg.tv/)
下面有各大maillist列表


###[介绍FFmpeg的Git基本操作](https://ffmpeg.org/git-howto.html)


###[Fmpeg Wiki](https://trac.ffmpeg.org/)

###[Complie Guide](https://trac.ffmpeg.org/wiki/CompilationGuide)

###FFmpeg的两个代码仓库
https://github.com/FFmpeg/FFmpeg
https://git.videolan.org/git/ffmpeg.git
https://git.ffmpeg.org/ffmpeg.git

###portring to android/arm 
[yixia/FFmpeg-Android](https://github.com/yixia/FFmpeg-Android)

重复这项任务的难点主要是
* configure的选项,*--disable-xxx*,*--enable-xxx*
* gcc的flag
```
CFLAGS="-O3 -Wall -mthumb -pipe -fpic -fasm \
  -finline-limit=300 -ffast-math \
  -fstrict-aliasing -Werror=strict-aliasing \
  -fmodulo-sched -fmodulo-sched-allow-regmoves \
  -Wno-psabi -Wa,--noexecstack \
  -D__ARM_ARCH_5__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5TE__ \
  -DANDROID -DNDEBUG"
```
* 编译时会遇到编译错误,要回过去改选项,甚至改代码.

##查看ffmepg log的一些NOTE
* 按照级别打开Log?
```
-loglevel debug
-loglevel verbose
```

###ffmpeg doxygen
[ffmpeg doxygen](http://ffmpeg.org/doxygen/trunk/index.html)

###ffplay加参数控制buffer,参考[Link](https://trac.ffmpeg.org/wiki/StreamingGuide#Latency)
>There is also apparently an option -fflags nobuffer which might possibly help, usually for receiving streams ​reduce latency.
```
ffplay -probesize 8000 -fflags nobuffer rtmp://172.17.196.3:1935/live/test
```

>Note:GOP设置1s和8s的区别是client显示第一个画面所需的时间,因为需要关键帧.
>另外,如果Server端做了Cache前一个关键帧的话,就会影响Latency.

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

###ffplay播放下面的链接时,提示协议部支持,需要openssl
```shell
ffplay https://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/bipbop_16x9_variant.m3u8
```
