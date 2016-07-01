#ExoPlayer
* [ExoPlayer](https://github.com/google/ExoPlayer)

###基础阅读项目
* [Developer guide](http://google.github.io/ExoPlayer/guide.html)


画一张新的Uml图.

###ExoPlayer怎么添加对一个流的播放支持(RTMP)?
* 封装成一个DataSource, 跟ExtractorSampleSource接上.

###Explayer Demo的流程
  1.PlayerActivity根据*contentType*创建*RendererBuilder*
  2.PlayerAcitivy创建DemoPlayer


##ExoPlayer ExtractorSampleSource 怎么使用 RtmpSource 的?
* ExtractorSampleSource是一个|SampleSource|, 是给TrackRender用的.

###Buffer是在哪个类里?
Allocate?