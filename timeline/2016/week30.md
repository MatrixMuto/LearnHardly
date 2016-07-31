*做一件事,就应该做到底.*

#Task
FFmpeg
Android

##React Native
先做简单了解,意义何在?
我熟悉的流媒体应用, React Native应该可以嵌入一个View的吧?
* 优势有哪些?
  * iOS,Android,*Learn Once, write everywhere*
* 开发环境,难点在与网络太慢
  * Node.js安装,[Link](https://nodejs.org/en/download/package-manager/#debian-and-ubuntu-based-linux-distributions)
    ```shell
    curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
    sudo apt-get install -y nodejs
    ```
  * Android Studio
  * react native benti
  ```
  npm install -g react-native-cli
  ```
* 简单使用

##那纯Native的应用框架有哪些?
* [googlesample/android-architecture](https://github.com/googlesamples/android-architecture.git)
  * MVP, rxjava
* Flux,Facebook提出的架构
  * android-flux例子
* Clean,
  * [The Clean Architecture](https://8thlight.com/blog/uncle-bob/2012/08/13/the-clean-architecture.html) 2012年8月13号
  * [Android-CleanArchitecture](https://github.com/android10/Android-CleanArchitecture)

###基于TCP连接的代码模型可以设计成哪些样子?
  1. 建立两个线程, 一个读,一个写.
  2. select模型

###什么叫CDN回源？
CDN网络Edge服务器缓存层未命中，向Orign服务器发请求的行为，叫回源?

###HLS比较全面的介绍
[HLS比较全面的介绍](http://yangchao0033.github.io/blog/2016/01/29/hls-1/)


###这段时间，还是聚焦在FFmpeg，以
* player
* rtp/rtcp
* rtsp
* rtmp,flv
* hls
* h.264
切入来总结

###两个模块交互的方式有几种？当然也可以概括为设计模式。
* 同步
* 异步

###C10K问题
[C10K问题](http://www.kegel.com/c10k.html)


