*Week 21	May 23, 2016	May 29, 2016*

#Live Streaming

##HOW: How to load-test/presses-test rtmp server?
FOUND: 
* [1](https://github.com/fillest/rtmp_load)

>如果是自己写代码测试的话，可以试用一下。

* [2](http://willstare.com/stress-testing-rtmp-server/)

>Blog，介绍了Flazr,简要的讲了整个测试过程。
我如何重复这个测试，
* 一台主机，当Server，网卡/CPU/内存什么要求。
* 一台主机，Tester，网卡/CPU/内存什么要求。
* 一台终端，真正播放Video的，可以是手机等。
* 一个路由or交换机？设备

* [3](http://www.load-testing-tools.com/rtmploadtesting.html)
>怎么实现RTMP应用的测试
>推荐了NeoLoad，支持RTMP，RTMPS，RTMPT
>这个页面还有其他如Clound Load Test，WebSocket Test等的测试介绍

###Summary
基本是用工具去测试了

|  1 |  111|
| --- | --- |
| Flazr   | ddf|
| Neoload |ss  |

>要依赖于你知道怎么去配置一个RTMP Server，(nginx-rtmp).


##MAIN: nginx-rtmp configuration.
##How to setup/config a nginx-rtmp server for test.
##哪些nginx-rtmp-module的配置文件支持哪些设置
##How nginx-rtmp for local content one stream

##最终能用脚本或形成几个常用的配置文件

> *Note:这个是需要系统学习的内容，从安装开始，这已经可以是一个完整的Doc了。*

###WebPages
* [1](https://obsproject.com/forum/resources/how-to-set-up-your-own-private-rtmp-server-using-nginx.50/)

``` 
从下载源码到编译配置运行，这是一个入门的好文章，但需自动化。
有提到，
    你可以用RTMP Server来转发其他服务商的RTMP流。
push rtmp://<other streaming service rtmp url>/<stream key>
```
* [nginx-rtmp – Configuration and possible solutions](http://www.helping-squad.com/nginx-rtmp-configuration-and-possible-solutions/) 

```
这里面有几个例子，有用到avconv来在本地生成一个rtmp的流，可能就是这样了。
还依赖ffmpeg/avconv/vlc等media方面工具的使用了。
```

```
application live1 {
live on;
record off;
exec avconv -i rtmp://localhost/live1/StreamKEY -c:v libx264 -preset veryfast -b:v 2000k -bufsize 4000k -c:a copy -s 1280x720 -r 30 -f flv rtmp://localhost/live2/StreamKEY2
}
```
* [nginx-rtmp with dash?](https://streamroot.readme.io/docs/nginx-rtmp)
```
    什么是Dash？？
    1. The stream is sent directly from an exterior rtmp source to the DASH / HLS live rtmp application
    2. The DASH / HLS live rtmp application pulls it stream from an exterior rtmp source
    3. The stream is sent from an exterior rtmp source to an nginx rtmp application that transcodes it and then sends it to the DASH / HLS live rtmp application
```

###Read Document:
* [Wiki of nginx-rtmp-module](https://github.com/arut/nginx-rtmp-module/wiki)
    
* [nginx doc](http://nginx.org/en/docs/) 
* [beginners guide](http://nginx.org/en/docs/beginners_guide.html)

---
#HOW: How to use OBS Studio?
##Ex 1
* [] ()

```
Server:rtmp://<ip>/live
Key:   test
```
##EX 1

---
##WHY: Why is rtmp://<ip>/live/test

---
##HOW: How to use tcpdump?
* [manpage of tcpdump](https://rtmpdump.mplayerhq.hu/rtmpdump.1.html)
```
```
* [1](https://danielmiessler.com/study/tcpdump/)
```
tcpdump的实用的例子
后续用FAQ的形式来记录用过的tcpdump命令
```

---
##How: How to anlnaye the pacp file？
##How: How to use wireshark?
* 用来分析学习RTMP的协议
```
发现立面有很多Adobe RTMP里文档没提到的命令。
先是拿命令的名字搜，没搜出来。
后来看到WireShark上有解析，这个是AMF0的Command。
所以，还要了解AMF0的Format
```

---
##Learn protocol RTMP
* [Wiki](https://en.wikipedia.org/wiki/Real_Time_Messaging_Protocol)
```
首先我应该通读上Wiki上提到的内容
```

---
##Learn AMF0 AMF3.....
* [Wiki of AMF](https://en.wikipedia.org/wiki/Action_Message_Format)
```
这里有Spec的下载链接
```

---
## 有哪些RTMP Player？
* [VLC Player]()
```
vlc rtmp://<ip>/live/test
```
* [avplay](https://libav.org/documentation/avplay.html#rtmp)
    * Setup ？
    * play rtmp ？
* [ffmpeg]()

---
## 与其他的RTMP Server比较
* Red5
* [Wowza](https://www.wowza.com/)

---
##How: How to follow the big-guys?
##Communcation with people
* [nginx-rtmp google groups](https://groups.google.com/forum/#!forum/nginx-rtmp)

---
#遇到的实际问题，
## avplay 出现黑屏 Week 21	May 23, 2016	May 29, 2016
        ```
        avplay rtmp://localhost/live/test
        ```
        上面的命令会出先没有图像的情况，而改用
        ```
        avplay rtmp://172.17.196.3/live/test
        ```
        就可以了
        不断的重试，肯定不是解决这个问题的办法。
        总结查这个问题的方法，找到每次出现的原因，解决，使同样原因的问题不再重现。
        建立在avplay使用的基础上

## 出现画面静止，vlc cpu 100%， 手机端也停止。
  server出问题？ or OBS出问题？
  
  
## Delay 分析
* OBS Delay分析
* nginx-rtmp Delay分析
* avplay,ffmpeg,vlc Delay分析

## avplay,vlc,这些开源播放器似乎对rtmp的播放支持不太好。

##FFmpeg Streaming Guide
* 可以推到MediaServer，也可以直接推给接收端。

``` shell
ffmpeg -y -loglevel warning -f dshow -i video="screen-capture-recorder" -vf crop=690:388:136:0 -r 30 -s 962x388 -threads 2 -vcodec libx264 -vpre baseline -vpre my_ffpreset -f flv rtmp:///live/myStream.sdp
```

##有哪些视频直播行业的门户？
  * 国内的
    * [斗鱼]()
    * [熊猫]()
    * [优酷]()
  * 国外的
    * [YouTube]()
    * [Twich]()
