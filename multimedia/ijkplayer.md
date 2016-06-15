###ijkplayer是怎么移植FFmpeg的?

###先看看ijkplayer怎么编辑FFmpeg的吧?
* 下载代码
  ijkplayer使用的是从[FFmpeg/FFmpeg](https://github.com/FFmpeg/FFmpeg)Fork的分支[Bilibili/FFmpeg](https://github.com/Bilibili/FFmpeg),
  下载之后,checkout到了特定的分支,并为本地仓库新建了branch.
* 编译
  <ijkplayer>/android/contrib/tools/do-compile-ffmpeg.sh
  大致是,
    1.设置CPU架构相关的脚本变量
    2.设定toolchain,用standalone的方式使用android-ndk
    3.调用ffmpeg的configure,生成Makefile或者是config.h?
    4.make
  整个脚本的最终目的是生成libijkffmpeg.so <--定制过的ffmpeg库.


###一个Player要直接哪些接口?哪些信息回调?
提供的接口
  * set url
  * prepare
  * start
  * seek
  * stop
  * setSurface
提供的信息
  * mediainfo
  * positon

