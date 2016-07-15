*[Week 27	July 4, 2016	July 10, 2016](http://www.epochconverter.com/weeks/2016)*

##上周在干什么?
* 看grafika, 为的是搞清楚Android的Graphics Architecture, 这周肯定要继续啃的.
  * 攒下的3个坑,没解啊.. Binder <-- gui <-- ui [binder+gui+ui](http://androidxref.com/5.1.1_r6/xref/frameworks/native/libs/)
  * 一个坑是EGL
  * 
* 然后在是些ffmpeg的testbed, 为的是熟悉ffmpeg, 这块骨头不确定该不该啃.
* H264的坑..
* 最近的目标是能出一个Android端的Broadcaster.
  * 内容上至少支持Camera, 其次是Virtual Disaplay.
  * 服务器上支持自己搭的nginx-rtmp, 然后是其他目标吧.
  * ??是不是在Android已经有这样的项目了??
    * 有人写了Yasea. *其实这上面, 简单做, 真讲不出难点*
   
* 欠一个PPT,讲流媒体服务的...
  * 重点是能够讲明白,
  * 流媒体应用实际中会遇到的问题会有哪些?
  * 这些问题有哪些方法去解决?
  * 是不是可以开始做这方面的实践.
* 欠着的RTMP的坑怎么填..

###想了想服务器的拓扑结构吧.
* 首先是个域名吧.
* 域名要通过DNS转成IP吧...
* 比如有3个地方的网络(移动联通电信),连到一个物理主机.
* 这个主机可以配置3个网卡,分别对接3个网络啊
* 然后就根据client的网络地址,分给它一个近点的Edge服务器.
* 上传的人总只能跟一个服务器交互吧,可能是Edge,可能是Main服务器.
* 其他Edge,发现要从另外的Edge拿流,那就查呗..总是一个个传过来的吧,可能中间还有Edge.
* 这就是CDN呗.
还是需要看书, 才能捋清楚这个概念.
[Wiki of CDN](https://en.wikipedia.org/wiki/Content_delivery_network)
其实现在很多软件都会偷偷的被当做Edge..360,迅雷,这些软件都会.

###[leetcode](https://leetcode.com/)
开始刷吧

###以下这些问题怎么解决?
直播常见的问题包括
    主播在不稳定的网络环境下如何稳定推流？
    偏远地区的观众如何高清流畅观看直播？
    直播卡顿时如何智能切换线路？
    如何精确度量直播质量指标并实时调整？
    移动设备上不同的芯片平台如何高性能编码和渲染视频？
    美颜等滤镜特效处理怎么做？
    如何实现播放秒开？
    如何保障直播持续播放流畅不卡顿？
先看播放端的一些逻辑策略..
  上面的这些问题, 是跟协议高度相关的.
  
