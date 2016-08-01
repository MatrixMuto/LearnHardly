*[Week 25	June 20, 2016	June 26, 2016](http://www.epochconverter.com/weeks/2016)*

###近期计划
* 巩固OpenMax IL层的知识点
  * OMX_Video.h的API调用流程
  * 运行,消息的整套机制
* 巩固Android Graphic的一些知识点
  * 能够按照[文档](https://source.android.com/devices/graphics/architecture.html),进行分享.
  * 总结一下经验
    * OMXCodec的使用
    * ANativeWindow
    * MediaCodec
* ExoPlayer上增加RTMP的实现
  * [Red5](https://github.com/Red5/red5-client/tree/master/src/main/java/org/red5/client/net)有rtmp,rtmps,rtmpe,rtmpt等的协议
  * ExoPlayer框架各种定制应该如何进行?

* Nginx-rtmp的流程

###Android Graphics Archtecture练习
疑惑:
* 是不是可以创建SurfaceXXX?但不显示在屏幕上?怎么做?
* Camera就可以设置一个SurfaceTexture给它,Camera会更新图像到texture里?

###什么是IP Camera?
[这个是IP Webcam](https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en)
局域网Camera分享

###为什么RTMP和H.264之间需要一层FLV?
猜测:RTMP会分Audio和Video,但只分Chunk大小,不知道H.264/AAC帧的大小,FLV知道?

###Intellij IDEA 大型项目受限硬盘,内存,处理器能力限制.

###比方说播放器到服务起的带宽不够,肯定要降码率(压缩率,分辨率,帧率),这肯定是服务器和播放端一起来做的这个事情.
没做过啊,所以不知道哪个方案更有效果,肯定是直接分分辨率吧
这个Adaptive不是RTMP协议的范畴

###波动的话,可以通过缓冲来控制,播放端自己可以把这个事情做了.

###Intellij IDEA CTRL+F11 是关于Bookmark的.
什么作用?

###在grafika的ContinuousCaptureAndroid中
Camera <- SurfaceTexutre <- mTextureId
然后在onFrameAvaliable中

通过
* eglMakeCurrent eglSurface->
* SurfaceTexture.updateTexImage->
* glDraw 
  > 这里会用到Shader,基础的概念是Program和<想不起来了>
* glSwapBuffer

###MediaProjection的一些接口
1.MediaProjection的createVirtualDisplay接口需要Surface.
2.TextureView中的SurfaceTexture -> Surface是可以的.
3.说明我的SurfaceTexture不太对.

###relay是什么?
好像是转播的一个概念?如果是转播的话,nginx-rtmp转播的流程是怎么样的?

###我能把Android的Looper搞清楚吗?
* 常用的用法
* 实现的一些细节

###终于想起要关掉Ubutnu的启动动画了
* 编辑**/etc/default/grub**,去掉**"quiet splash"**参数
* 调用**sudo update-grub2**来落实更新
* 卸载plymouth-theme-ubuntu-text??
[StackOverflow Link](http://askubuntu.com/a/33420)

###我能把android.os.Parcelable这个类搞清楚么?

###[ExoPlayer.TrackRender](../../multimedia/exoplayer.md#exoplayertrackrender)

###以前看过的,Android Studio的断点的高级技巧
* 加上不会中断的断点
* 不改代码加Log, 会输出到它的Console窗口
* 条件断点,还不会用
