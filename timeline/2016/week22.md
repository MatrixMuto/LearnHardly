#从知乎上看到个WebVR的东西，可能是VR视频站的一些标准吧
* WebVR
[zhihu](https://www.zhihu.com/question/46588080/answer/101921236)
[WebVR](https://mozvr.com/webvr-spec/)

##Streaming
* RTMP HLS

##VR
* VR内容有哪些领域
  360 Video，Game

##configure框架
* autotool
* shell

##Linode
[Linode上配置nginx](https://www.linode.com/docs/websites/nginx/how-to-configure-nginx)

##Shell语法
```
VAR_NAME="value"
$VAR_NAME
${VAR_NAME}
```
##Makefile语法,文本替换等的规则d
```
VAR_NAME=xxxxx
$(VAR_NAME)
```

##搜索了
* nginx rtmp delay
  发现delay可能就是在两端
  - [ ] [How to reduce latency](https://github.com/arut/nginx-rtmp-module/issues/378)
  这里会很多人提过类似的需求
  
* 看了nginx-rtmp-module的文档
  发现是可以用Flash播放器来测试我搭的nginx服务起的


* nginx rtmp jwplayer
[可能找个Video看一下](https://www.youtube.com/watch?v=GtoTE8oslNA)
[vultr的Setup Nginx on Ubuntu to Stream Live HLS Video](https://www.vultr.com/docs/setup-nginx-on-ubuntu-to-stream-live-hls-video)
[wowza的文档](https://www.wowza.com/forums/content.php?484-How-to-use-JW-Player-with-Wowza-Streaming-Engine#rtmp_example)

##感觉我的目标就是搭一个简单的视频B站...



##关于思考项目管理和推进.
- [ ] [从程序员到项目管理](http://developer.51cto.com/art/201211/364725.htm)
- [ ] [这里推荐了6本书](http://www.imooc.com/article/1230)


##发现了nginx-rtmp-module的stat,还有它的branch管理
- [ ] [nginx-rtmp-module的配置项目](https://github.com/arut/nginx-rtmp-module/wiki/Directives)


##Nginx相关的电子书出版商的书
- [ ] [Nginx-module-extension](https://www.packtpub.com/networking-and-servers/nginx-module-extension)

---
##怎么做IT工作纪要?

了解了:

发现了:
* nginx-rtmp

解决了:

学会了:

看了什么书,Blog...

###Media System
[Comparison](https://en.wikipedia.org/wiki/Comparison_of_streaming_media_systems)

##发现
* android端如何推流.
[stackoverflow](http://stackoverflow.com/questions/29018606/android-stream-camera-as-rtmp-stream)
[java cv](https://github.com/bytedeco/javacv)
[javacpp-presets](https://github.com/bytedeco/javacpp-presets)

##RTMP协议还需要看AMF0,AMF3等协议,因为OBS上用到了.
但是AMF0只是定义格式,并未讲具体的功能.


##试用Red5
[Red5-server](https://github.com/Red5/red5-server)
[Red5](http://red5.org/) 
[Wowza](https://www.wowza.com/)



##推流端按照什么标准去实现?
  集成SDK?
  适配各大视频站,OBS就是这样的.
  私有协议?
  FMS有吗?