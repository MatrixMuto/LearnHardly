
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

