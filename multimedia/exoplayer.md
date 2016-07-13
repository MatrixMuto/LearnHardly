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

###ExoPlayer.TrackRender
* 这是个抽象,有挺多的子类,可以是Decoder,比如MediaCodecTrackRender,但这是一个实例
* 在外初始化好之后,通过exoplayer.prepare(TrackRender...)接口,传多个Rendener给exoplayer

###ExoPlayer的设计上,从接口当真正实现,中间还有一层wrapper,为什么?
作为|interface|不能动, 因为动的话, 所有用ExoPlayer的使用者都得改代码.
有了impl这个接口, User的代码不动,接口的调用顺序不好动.
实现和组装可以分开,|ExoPlayerImpl|改自己的结构,只要在|ExoPlayerInternal|作调整就可以了.
我是这么理解的.
可能这个是什么设计模式吧.

###ExtractingLoadable
ExtractingLoadable这个是让Extractor 从 DataSource 读数据.
