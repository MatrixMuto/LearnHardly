<<<<<<< Updated upstream
###FFmpeg文档翻译
[Link](https://wanglongqi.github.io/tools/2015/02/13/ffmpegcn/)
=======
#达到什么样的目标.
因为FFmpeg是个超大的开源软件体..需要花超多的时间来完全掌握.
如果目标不明确,会浪费很多时间...
* 熟悉软件应用
* 熟悉框架
* 熟悉常用的模块
>>>>>>> Stashed changes

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

* 比如我想要把Apple HLS的测试媒体的图像数据DUMP下来?
  * 我怎么制定HLS Adapative的分辨率呢?

###导出yuv数据
```
ffmpeg -i /tmp/test%d.Y /tmp/out.mpg
ffmpeg -i /tmp/test.yuv /tmp/out.avi
ffmpeg -i mydivx.avi hugefile.yuv
ffmpeg -i /tmp/a.wav -s 640x480 -i /tmp/a.yuv /tmp/a.mpg
ffmpeg -i /tmp/a.wav -ar 22050 /tmp/a.mp2
ffmpeg -i /tmp/a.wav -map 0:a -b:a 64k /tmp/a.mp2 -map 0:a -b:a 128k /tmp/b.mp2
ffmpeg -i snatch_1.vob -f avi -c:v mpeg4 -b:v 800k -g 300 -bf 2 -c:a libmp3lame -b:a 128k snatch.avi
ffmpeg -i foo.avi -r 1 -s WxH -f image2 foo-%03d.jpeg
ffmpeg -f image2 -framerate 12 -i foo-%03d.jpeg -s WxH foo.avi
ffmpeg -f image2 -pattern_type glob -framerate 12 -i 'foo-*.jpeg' -s WxH foo.avi
ffmpeg -i test1.avi -i test2.avi -map 1:1 -map 1:0 -map 0:1 -map 0:0 -c copy -y test12.nut
ffmpeg -i myfile.avi -b 4000k -minrate 4000k -maxrate 4000k -bufsize 1835k out.m2v
ffmpeg -i src.ext -lmax 21*QP2LAMBDA dst.ext
```

###导出H.264数据
```
命令行：

ffmpeg -i 20130312_133313.mp4 -codec copy -bsf: h264_mp4toannexb -f h264 20130312_133313.264

说明：

 -i 20130312_133313.mp4 :是输入的MP4文件

-codec copy：从MP4封装中进行拷贝
-bsf: h264_mp4toannexb：从MP4拷贝到annexB封装
-f h264：采用h.264格式
20130312_133313.264：输出的文件名称
```