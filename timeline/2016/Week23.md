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
