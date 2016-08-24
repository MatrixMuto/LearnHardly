# Platform Architecture
![android stack](../../res/android-stack_2x.png)
* Linux Kernel
* HAL
* Android Runtime
  从Android 5.0(API level 21)开始, 每个应用运行在自己的进程中,有自己独立的Android Runtime.
  ART是为了在低内存设备上运行多个虚拟机,执行DEX文件.
  DEX是一个字节码,为Android设计的优化过的,为了更少的内存占用.
  编译工具有Jack,编译Java代码,输出DEX字节码.

  ART的主要特征:
  * Ahead-of-time (AOT) and just-in-time (JIT) compilation
  * Optimized garbage collection (GC)
  * Better debugging support, including a dedicated sampling profiler, 
  detailed diagnostic exceptions and crash reporting, and the ability 
  to set watchpoints to monitor specific fields

  在Android 5.0之前,Android runtime是Dalvik. 如果App能在ART上运行,那应该也能在Dalvik上运行.
  反过来就不一定了.?
* Naitve C/C++ Libraries
* Java API Framework
  * View System
  * Resource Manager
  * Notification Manager
  * Activity Manager
  * Content Providers
* System Apps
## Java 8 语言功能
Android N支持Java 8语言功能

* 支持的Java 8语言功能
  - 默认和静态接口方法?
  - Lambda表达式
  - 重复注解
  - 方法引用
* 启用Java 8共能和Jack工具链
  如过要用,需要用新的Jack具链

   > 以下是构建 Android Dalvik 可执行文件可用的两种工具链的对比：

    旧版 javac 工具链：
    javac (.java --> .class) --> dx (.class --> .dex)
    新版 Jack 工具链：
    Jack (.java --> .jack --> .dex)
* 配置Gradle
  
  ```
  android {
    ...
    defaultConfig {
      ...
      jackOptions {
        enabled true
      }
    }
    compileOptions {
      sourceCompatibility JavaVersion.VERSION_1_8
      targetCompatibility JavaVersion.VERSION_1_8
    }
  } 
  ```
* 已知问题
  不能和Instant Run一起用.因为Jack不会生成一些中间文件.
## 在ART上验证应用行为 ???
[介绍ART和Dalvik](http://source.android.com/devices/tech/dalvik/index.html)
