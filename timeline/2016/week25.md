

###Android Graphics Archtecture练习
疑惑:
* 是不是可以创建SurfaceXXX?但不显示在屏幕上?怎么做?

###什么是IP Camera?
[这个是IP Webcam](https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en)
局域网Camera分享

###为什么RTMP和H.264之间需要一层FLV?
猜测:RTMP会分Audio和Video,但只分Chunk大小,不知道H.264/AAC帧的大小,FLV知道?

###Intellij Idea 大型项目受限硬盘,内存,处理器能力限制.

###比方说播放器到服务起的带宽不够,肯定要降码率(压缩率,分辨率,帧率),这肯定是服务器和播放端一起来做的这个事情.
这个Adaptive不是RTMP协议的范畴

###波动的话,可以通过缓冲来控制,播放端自己可以把这个事情做了.
