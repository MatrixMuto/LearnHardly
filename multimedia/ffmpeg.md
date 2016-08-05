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

#工程编译
##configure
* --disable-all 其他的模块都不会编译了,但是会编译libavutil.a

* 会生成 *config.mak* 文件, 被 *Makefile* 引用, 包含很多宏定义.
  * CC
* 会生成 *.config* 文件, 在Makefile里,被用来生成 *config.h*.

##config.mak
* 文件中有很多'!'开头的行.
    在Makefile中,'!'与其他字符一样,是变量名的一部分~,
    ```makefile
    !CONFIG_DECODERS=yes # 只是定义了个变量而已, CONFIG_DECODERS会是''
    ```
* 
##Makefile


##common.mak

##porting到Android的方式
* [yixia/FFmpeg-Android](https://github.com/yixia/FFmpeg-Android)

```sh
#!/bin/bash

DEST=`pwd`/build/ffmpeg && rm -rf $DEST
SOURCE=`pwd`/ffmpeg

#若没有ffmpeg目录,则下载源代码
if [ -d ffmpeg ]; then
  cd ffmpeg
else
  git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
  cd ffmpeg
fi

#切换代码到指定的版本号(ffmpeg-version文件中),打patch
git reset --hard
git clean -f -d
git checkout `cat ../ffmpeg-version`
patch -p1 <../FFmpeg-VPlayer.patch
[ $PIPESTATUS == 0 ] || exit 1

git log --pretty=format:%H -1 > ../ffmpeg-version

TOOLCHAIN=/tmp/vplayer
SYSROOT=$TOOLCHAIN/sysroot/

#若工具链目录不存在,用NDK生成工具链到目录
if [ ! -d ${TOOLCHAIN} ]; then
$ANDROID_NDK/build/tools/make-standalone-toolchain.sh --platform=android-14 --install-dir=$TOOLCHAIN
fi

export PATH=$TOOLCHAIN/bin:$PATH
export CC="ccache arm-linux-androideabi-gcc"  # ccache是一个在重新编译时的加速工具.
export LD=arm-linux-androideabi-ld
export AR=arm-linux-androideabi-ar

CFLAGS="-O3 -Wall -mthumb -pipe -fpic -fasm \
  -finline-limit=300 -ffast-math \
  -fstrict-aliasing \
  -fmodulo-sched -fmodulo-sched-allow-regmoves \
  -Wno-psabi -Wa,--noexecstack \
  -D__ARM_ARCH_5__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5TE__ \
  -DANDROID -DNDEBUG"

FFMPEG_FLAGS="--target-os=linux \
  --arch=arm \
  --enable-cross-compile \
  --cross-prefix=arm-linux-androideabi- \
  --enable-shared \
  --disable-symver \
  --disable-doc \
  --disable-ffplay \
  --disable-ffmpeg \
  --disable-ffprobe \
  --disable-ffserver \
  --disable-avdevice \
  --disable-avfilter \
  --disable-encoders \
  --disable-muxers \
  --disable-filters \
  --disable-devices \
  --disable-everything \
  --enable-protocols  \
  --enable-parsers \
  --enable-demuxers \
  --enable-decoders \
  --enable-bsfs \
  --enable-network \
  --enable-swscale  \
  --disable-demuxer=sbg \
  --disable-demuxer=dts \
  --disable-parser=dca \
  --disable-decoder=dca \
  --enable-asm \
  --enable-version3"


for version in neon armv7 vfp armv6; do

  cd $SOURCE

  case $version in
    neon)
      EXTRA_CFLAGS="-march=armv7-a -mfpu=neon -mfloat-abi=softfp -mvectorize-with-neon-quad"
      EXTRA_LDFLAGS="-Wl,--fix-cortex-a8"
      ;;
    armv7)
      EXTRA_CFLAGS="-march=armv7-a -mfpu=vfpv3-d16 -mfloat-abi=softfp"
      EXTRA_LDFLAGS="-Wl,--fix-cortex-a8"
      ;;
    vfp)
      EXTRA_CFLAGS="-march=armv6 -mfpu=vfp -mfloat-abi=softfp"
      EXTRA_LDFLAGS=""
      ;;
    armv6)
      EXTRA_CFLAGS="-march=armv6"
      EXTRA_LDFLAGS=""
      ;;
    *)
      EXTRA_CFLAGS=""
      EXTRA_LDFLAGS=""
      ;;
  esac

  PREFIX="$DEST/$version" && mkdir -p $PREFIX
  FFMPEG_FLAGS="$FFMPEG_FLAGS --prefix=$PREFIX"

  ./configure $FFMPEG_FLAGS --extra-cflags="$CFLAGS $EXTRA_CFLAGS" --extra-ldflags="$EXTRA_LDFLAGS" | tee $PREFIX/configuration.txt
  cp config.* $PREFIX
  [ $PIPESTATUS == 0 ] || exit 1

  make clean
  make -j4 || exit 1
  make install || exit 1

  rm libavcodec/inverse.o
  $CC -lm -lz -shared --sysroot=$SYSROOT -Wl,--no-undefined -Wl,-z,noexecstack $EXTRA_LDFLAGS libavutil/*.o libavutil/arm/*.o libavcodec/*.o libavcodec/arm/*.o libavformat/*.o libswresample/*.o libswscale/*.o -o $PREFIX/libffmpeg.so

  cp $PREFIX/libffmpeg.so $PREFIX/libffmpeg-debug.so
  arm-linux-androideabi-strip --strip-unneeded $PREFIX/libffmpeg.so

done
```

* [mconf/android-ffmpeg](https://github.com/mconf/android-ffmpeg/blob/master/jni/Android.mk)
  这个项目的脚本最终可以 *ndk-build* 来编译.

###在提前H.264时遇到些问题,看到[使用FFMPEG类库分离出多媒体文件中的H.264码流](http://blog.csdn.net/leixiaohua1020/article/details/11800877)解惑了.
>在使用FFMPEG的类库进行编程的过程中，可以直接输出解复用之后的的视频数据码流。只需要在每次调用av_read_frame()之后将得到的视频的AVPacket存为本地文件即可。
经试验，在分离MPEG2码流的时候，直接存储AVPacket即可。
在分离H.264码流的时候，直接存储AVPacket后的文件可能是不能播放的。
如果视音频复用格式是TS（MPEG2 Transport Stream），直接存储后的文件是可以播放的。
复用格式是FLV，MP4则不行。
经过长时间资料搜索发现，FLV，MP4这些属于“特殊容器”，需要经过以下处理才能得到可播放的H.264码流：
1.第一次存储AVPacket之前需要在前面加上H.264的SPS和PPS。这些信息存储在AVCodecContext的extradata里面。
并且需要使用FFMPEG中的名为"h264_mp4toannexb"的bitstream filter 进行处理。
然后将处理后的extradata存入文件
2.通过查看FFMPEG源代码我们发现，AVPacket中的数据起始处没有分隔符(0x00000001), 也不是0x65、0x67、0x68、0x41等字节，所以可以AVPacket肯定这不是标准的nalu。其实，AVPacket前4个字表示的是nalu的长度，从第5个字节开始才是nalu的数据。所以直接将AVPacket前4个字节替换为0x00000001即可得到标准的nalu数据。
具体代码如下：

基本是这样.

