##这周想要试着架构一下Android推流端
  参照WebRTC?
##不小心搜到Google VR SDK
  [Google VR](https://developers.google.com/vr/)
  [Google+ Group](https://plus.google.com/communities/111524380182206513071)

用gradle-experimental:0.7.0写build.gradle文件时,
dependencies要在model的外面.

##HandlerThread
HandlerThread有几种用法?
  1.配合Handler
  
  2.集成创建新的类?
quit和quitsafely怎么调用?

要去熟悉Camera2和Camera相关的API么?
居然一点都想不起来怎么弄,是不熟悉还是方法有问题?


##sudo service srs start
这里service是个什么鬼?


##讨论
* Streaming Server应用场景
  1.各种直播
  2.摄像头(DropCamera,小蚁,乐橙,萤石,等等)

* 协议选择(RTMP,HLS) DASH? Smooth?

* 技术选型
  * 推流端, obs? ffmpeg? vlc?
  * 播放端, ffmpeg? vlc? ExoPlayer?
  * 服务器端 red5? nginx-rtmp?

* 跨平台角度
  * 推流端, 嵌入式平台,Android平台
  * 播放端, iOS, Android, Flash
  * 服务器, Ubuntu,CentOS,BSD,Windows?
  
 
##ExoPlayer
* [ExoPlayer](https://github.com/google/ExoPlayer)
* PlayerActivity
  onShown会调用preparePlayer
* 状态是preparing, buffering, ready
##VLC-android

编译居然说一些工具需要最新版的gettext
我自己怎么编译安装新的版本呢?
```
export ANDROID_NDK=/home/wq1950/Software/android-ndk-r11c
export ANDROID_SDK=/home/wq1950/Software/android-sdk-linux
```


##Camera2的源码
https://android.googlesource.com/platform/packages/apps/Camera2/

##GLSurfaceView,SurfaceView,TextureView,Surface对比?


##自动测试
google的UIAnimator

##通常代码走到一个点,配置完了,后面的流程对于当前的类来讲,都是回调了.
我去哪找接下来的流程??
1.线程角度,主线程还会执行什么代码?
配置的那些类里,会启动什么线程?(难)
配置的那些类里,设给了它们什么回调,每个回调打Log,或者下断点.
2.知道会有什么回调之后?搞清楚回调又是谁调的.
可以看堆栈呗..


##那些视频云
Streaming Server应用场景
参考各大云商的多媒体服务,
国内:
[腾讯云视频](https://www.qcloud.com/solution/video.html),
[百度音视频直播 LSS](https://bce.baidu.com/product/lss.html),
[阿里云-多媒体解决方案](https://media.aliyun.com/),
[金山云直播 KLS](https://www.ksyun.com/proservice/cloud_live),
[网易云信](http://netease.im/),
国外:
[Twitch](https://www.twitch.tv/),
[YouTube](https://www.youtube.com/),
[Amazon](https://aws.amazon.com/cn/?nc2=h_lg)

* [阿里云-多媒体解决方案](https://media.aliyun.com/)
  * 解决方案
    * 视频监控
    * 在线视频制作分享
    * 视频直播
    * 新媒体
  * 案例:
    * 乐橙
    * 短趣 - 趣拍
    * 在线教育
    * 萤石
  * 功能:

* 百度智能多媒体解决方案
  * [音视频直播 LSS](https://bce.baidu.com/product/lss.html)
  * 案例:
    * 全民直播 - 直播平台
    * Insta360 - 全景直播
    * 作业帮 - 在线教育
  * [音视频点播 VOD](https://bce.baidu.com/product/vod.html)

* 金山云
  * [云直播 KLS](https://www.ksyun.com/proservice/cloud_live)
    * 案例:
      * 小蚁
      * 蛙趣
  * [云点播 KVS](https://www.ksyun.com/proservice/cloud_broadcast)
    * 案例:
      * 蛙趣
      * 宝宝巴士
      * 麦唱
  * [云转码 KET](https://www.ksyun.com/proservice/cloud_transcode)
    * 案例:
      * 蛙趣
      * 宝宝巴士
      * 麦唱

* [网易云信](http://netease.im/)
  * [实时音视频](http://netease.im/netcall)
    * 场景
      * 社交
      * 远程医疗
      * 互动教育
      * 视频会议
    * 案例
      * 网易云课堂
      * 在家点点
      * 有糖
      * 顺丰
      * 随身暴风英雄
  * [视频云-直播功能](http://netease.im/vcloud)
    * 场景
      * 在线教育
      * 视频直播
      * 娱乐直播
      * 会场直播
    * 案例:
      * 网易云课堂
      * 网易青果 - 监控

* [腾讯云视频](https://www.qcloud.com/solution/video.html)
  * 视频行业架构
    * 游戏直播
    * 视频门户
    * 在线教育
    * 美女主播
    * 垂直社交
  * 功能
    * 点播
    * 直播
    * 互动直播
    * 云通信
  * 案例
    * iCNTV
    * 齐齐互动视频
    * 优答 - 在线教育
    * 龙珠直播
    * ZEALER - 视频直播
    * ABC360 - 在线教育

* [Amazon](https://aws.amazon.com/cn/?nc2=h_lg)


##协议选择
* 协议
  * RTMP
  * RTSP
  * UDP
  * FLV
  * HLS拉流
  
##服务器方案
* 有哪些Streaming Server?
  * [NGINX-based Media Streaming Server](https://github.com/arut/nginx-rtmp-module)
  * [Red5]()
  * [Wowza]()
  * [FMS]()
  * [Simple RTMP Server](https://github.com/ossrs/srs)
  * [CRTMPD]()
* 功能对比,参考[Link](https://github.com/ossrs/srs/tree/2.0release#compare)
* 性能对比,参考[Link](https://github.com/ossrs/srs/tree/2.0release#performance)


##播放器端框架选择
* vlc
* ffmpeg
* libav
* ExoPlayer
  * LICESENSE?
  * 功能
    * Codec(Video:,,,, Audio:)
    * 
  * 平台
    * Android

##<推流端>方案选择?
* OBS
  * LICENSENSE
  * 功能 
  * 平台
    * Linux
    * Windows
* ffmpeg
###模块有哪些?
* 采集
* Encoder
* Muxer
