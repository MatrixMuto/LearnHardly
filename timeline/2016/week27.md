*[Week 27	July 4, 2016	July 10, 2016](http://www.epochconverter.com/weeks/2016)*


###取名字有纠结症,取水果名~
[Link](http://english.cri.cn/7046/2010/05/28/102s572871.htm)

###GitHub,仓库内给予Markdown的跳转链接怎么做?
*做timeline整理的时候可以用上*
在github上浏览的时候,它对markdown类型的文件,会生成带'#'的章节链接,空格会转成'-',中文不变,'.'去掉,大写转小写

###avformat_network_init干嘛了?
```c
/**
 * Do global initialization of network components. This is optional,
 * but recommended, since it avoids the overhead of implicitly
 * doing the setup for each session.
 *
 * Calling this function will become mandatory if using network
 * protocols at some major version bump.
 */
int avformat_network_init(void);

/**
 * Undo the initialization done by avformat_network_init.
 */
int avformat_network_deinit(void);
```

###avformat库的依赖库
```
FFMPEG_DIR = ../ffmpeg

DEP  = -lavformat -lavcodec -lavfilter -lavdevice -lavutil
DEP2 = -lcrypto -lssl -lpthread -lm -lz
DEP3 = -L$(FFMPEG_DIR)/libswresample -lswresample

all: main.c
	cc main.c -I$(FFMPEG_DIR) $(DEP) $(DEP2) -o main

```
最简单的ffmpeg环境Makefile了...

>今天又被自己坑了,gcc命令里链接库'-lxxx'的顺序要注意!
>用.a和用.so的区别?
用静态库作依赖库的话,只会链接main函数开始,被用到的函数,减少可执行文件的体积.

###av_register_all
为什么要执行这个函数?
执行的话,由于用到了很多可能其实不必要的依赖库,所以要configure的时候,disable掉.
不执行的话,就要用av_register_input_format和av_register_output_format去注册想要用的format.
```
/**
 * Initialize libavformat and register all the muxers, demuxers and
 * protocols. If you do not call this function, then you can select
 * exactly which formats you want to support.
 *
 * @see av_register_input_format()
 * @see av_register_output_format()
 */
void av_register_all(void);

void av_register_input_format(AVInputFormat *format);
void av_register_output_format(AVOutputFormat *format);
```

###libva.so
链接了av_register_all后,出现链接错误.
```
ffmpeg/libavcodec/vaapi_encode.c:46: undefined reference to `vaCreateBuffer'
```
它是[Link](http://01org.github.io/libva_master_doxygen/index.html)的api函数.
```
Video Acceleration (VA) API
Introduction

The main motivation for VA-API (Video Acceleration API) is to enable hardware accelerated video decode and encode at various entry-points (VLD, IDCT, Motion Compensation etc.) for the prevailing coding standards today (MPEG-2, MPEG-4 ASP/H.263, MPEG-4 AVC/H.264, VC-1/VMW3, and JPEG).

VA-API is split into several modules:

Core API
H.264 encoding API
Video processing API
```

###libbz2.so
```
ffmpeg/libavformat/matroskadec.c:1395: undefined reference to `BZ2_bzDecompressInit'
```
在链接命令里加'-lbz2'

###av_read_frame
```c
/**
 * Return the next frame of a stream.
 * This function returns what is stored in the file, and does not validate
 * that what is there are valid frames for the decoder. It will split what is
 * stored in the file into frames and return one for each call. It will not
 * omit invalid data between valid frames so as to give the decoder the maximum
 * information possible for decoding.
 *
 * If pkt->buf is NULL, then the packet is valid until the next
 * av_read_frame() or until avformat_close_input(). Otherwise the packet
 * is valid indefinitely. In both cases the packet must be freed with
 * av_packet_unref when it is no longer needed. For video, the packet contains
 * exactly one frame. For audio, it contains an integer number of frames if each
 * frame has a known fixed size (e.g. PCM or ADPCM data). If the audio frames
 * have a variable size (e.g. MPEG audio), then it contains one frame.
 *
 * pkt->pts, pkt->dts and pkt->duration are always set to correct
 * values in AVStream.time_base units (and guessed if the format cannot
 * provide them). pkt->pts can be AV_NOPTS_VALUE if the video format
 * has B-frames, so it is better to rely on pkt->dts if you do not
 * decompress the payload.
 *
 * @return 0 if OK, < 0 on error or end of file
 */
int av_read_frame(AVFormatContext *s, AVPacket *pkt);
```

###error: ‘for’ loop initial declarations are only allowed in C99 mode
```
main.c:28:2: error: ‘for’ loop initial declarations are only allowed in C99 mode
  for (int i=0;i<10;i++)
  ^
main.c:28:2: note: use option -std=c99 or -std=gnu99 to compile your code
```

###[hls,applehttp @ 0x27930e0] Invalid timestamps stream=2, pts=921021, dts=924024, size=497
出这个log的原因是,ffmpeg的代码上有一个dts和pts的判断,如果pts小于dts的话,就会输出这行.
需要pts和dts的基础来解释这个...
* pts在多媒体框架中有什么作用?
* dts

###avformat_open_input对hls协议的open流程是怎么样的?
以及avformat的角色...

###VSYNC是个啥?
*在ffmpeg.h里也看到了VSYNC这个玩意,之前是在android的graphics看到.*
vsync应该是一个硬件上的东西,很可能是display驱动发出来的信号?
>What Is V-Sync?
It's short for vertical synchronization, an optional setting on your graphics card that throttles the frames being drawn to match the number of times your monitor refreshes itself every second.

* [Android中的VSYNC](https://source.android.com/devices/graphics/implement.html)

###Codec-specific Data
[Codec-specific Data](https://developer.android.com/reference/android/media/MediaCodec.html)
* SPS
* PPS
* VPS

###avformat_open_init
此函数主要通过|init_input|完成功能


###ssh终端和串口终端有什么区别?
因为我用ssh终端,可能无法显示什么东西出来?

###作为capturer/broadcaster不同的帧率,pts,dts值怎么填?

###网络摄像头功能:图像侦测,声音侦测
怎么把这个功能实现到摄像头端,服务器端,播放端?

###Segmentation fault (core dumped)
出现这个之后,效率最高的查法是什么?
* gdb main
* 

###ffmpeg推文件到rtmp服务器的live上
```
ffmpeg -re -i ~/Videos/test.flv -f flv -rtmp_playpath test -rtmp_app live rtmp://localhost:1935/
```

###给树莓派装系统
[Link](https://www.raspberrypi.org/documentation/installation/installing-images/linux.md)
基本就几步
* 下载镜像
* umount
  ```
  umount /dev/sd*x*1
  ```
* 写卡
  ```
   sudo dd bs=4M if=2016-05-27-raspbian-jessie.img of=/dev/sd*x*
  ```
* sync一下

###bitbucket, for team是什么意思?
[bitbucket](https://bitbucket.org/)

###mercurial
在下载libx265的仓库的时候,居然用的命令是'hg',还说这是mercurial结构的仓库

###gdb with args
```
gdb --args ffmpeg_g -re -i ~/Videos/test.flv -f flv -rtmp_playpath test -rtmp_app live rtmp://localhost:1935/
```
[StackOverflow](http://stackoverflow.com/a/6121299)

###我怎么以最好的方式使用FFmpeg里的rtmp库?
```c
#define RTMP_PROTOCOL(flavor)                    \
static const AVClass flavor##_class = {          \
    .class_name = #flavor,                       \
    .item_name  = av_default_item_name,          \
    .option     = rtmp_options,                  \
    .version    = LIBAVUTIL_VERSION_INT,         \
};                                               \
                                                 \
const URLProtocol ff_##flavor##_protocol = {     \
    .name           = #flavor,                   \
    .url_open       = rtmp_open,                 \
    .url_read       = rtmp_read,                 \
    .url_read_seek  = rtmp_seek,                 \
    .url_read_pause = rtmp_pause,                \
    .url_write      = rtmp_write,                \
    .url_close      = rtmp_close,                \
    .priv_data_size = sizeof(RTMPContext),       \
    .flags          = URL_PROTOCOL_FLAG_NETWORK, \
    .priv_data_class= &flavor##_class,           \
};

RTMP_PROTOCOL(rtmp)
RTMP_PROTOCOL(rtmpe)
RTMP_PROTOCOL(rtmps)
RTMP_PROTOCOL(rtmpt)
RTMP_PROTOCOL(rtmpte)
RTMP_PROTOCOL(rtmpts)
```
|avformat.h|包扩了|avio.h|这个头文件,这里是avio一系列的接口.


###'~'是按位取反. '^'是位异或
```
val |= XXX_FLAG;  //置标志位
val &= ~XXX_FLAG; //清标志位
```

###为什么ffmpeg起了N多线程?

###gdb怎么看线程信息?

###rtp播放端在发现少了少量的rtp包的时候,怎么样控制马赛克?
分rtp(h.264) rtp(ts)

###android/linux时间相关.
* 在ExoPlayer里好像是通过HandlerThread的Handler发message来控制时间的.
  ```java
  sendEmptyMessageDelay();
  wait(span_in_MS);
  ```
* C代码的话,应该是用|pthread_cond_wait|还是|usleep|?
* nginx里面呢?
  ```c
  //ngx_time.h
  #define ngx_gettimeofday(tp)  (void) gettimeofday(tp, NULL);
  #define ngx_msleep(ms)        (void) usleep(ms * 1000)
  #define ngx_sleep(s)          (void) sleep(s)
  ```

###内存拷贝
* android的内存拷贝的带宽大概有多少?
  一般都有  ~1 GB/S
* 为什么需要避免内存拷贝?
  
* 720P@30的YUV数据拷贝会耗费内存带宽,对CPU有什么影响
  40 MB/S

###grafika中,camera和mediacodec结合的例子



###又遇到android studio卡住,还是网络原因
出问题的网络原因是因为用了代理,|gradle.properties|文件定义了代理,
但是为什么testCompile又要用到网络呢,算了,不管.

###命名规范
* android layout id ?
* string name

###什么时候用HandlerThread而不是Thread,为什么?

###面试题网站
[百面](http://www.100mian.com/)