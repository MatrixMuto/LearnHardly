
###[开发手册](https://webrtc.org/native-code/development/)
* 环境变量
```shell
export GYP_DEFINES="OS=android"
```
* 编译命令
  * ninja,后面的目标名,是在别的步骤里生成的. *out/Debug*目录会有一个*build.ninja*总文件.  
  ```
  ninja -C out/Debug AppRTCDemo
  ``` 
  * gyp文件,Generate your project这个脚本工具的.
  总而言之,webrtc里的工程工具都是不熟悉的技术...
* 下载代码,这俩命令执行的前提是,把啥bin加到**PATH**里了.
  ```shell
  fetch --nohooks webrtc_android
  gclient sync
  ```
* 更新代码
  ```
  git pull
  ```

## GYP_DEFINES的定义影响哪些命令?


## example peerconnection

## DataChannel??

## 配置多个子网来学一下STUN和TURN,ICE协议

## 搭一个外网环境的服务器,使得连一个LAN的两个Android设备, 能互相通话.
- webrtc-android中有AppRTCDemo, 但是它用的服务器地址是被墙的,
- AppRTCDemo是可以用浏览器的直接WebRTC的.
- 那个服务器器代码是开源的. 放到内网上应该问题不大?
  [repo地址](https://github.com/webrtc/apprtc)
  - 这网站需要框架和服务器~
  >Running AppRTC locally requires the Google App Engine SDK for Python and Grunt.
  - 这个网站需要一定`turnserver`

- turn server
  [rfc5766-turn-server](https://github.com/coturn/rfc5766-turn-server)
  [coturn](https://github.com/coturn/coturn)
  
## 搭建AppRTCDemo服务
按照Repo的指导搭一遍
- [Google Cloud SDK](https://cloud.google.com/sdk/docs/)安装
  
## iOS 上的浏览器都不太能支持WebRTC？
