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
