> android studio是基于Intellij IDEA的,所以也会包括Intellij IDEA的内容.

###以前看过的,Android Studio的断点的高级技巧
* 加上不会中断的断点
* 不改代码加Log, 会输出到它的Console窗口
* 条件断点,还不会用

###在导入一个纯Java项目时,gradle文件怎么写,才能尽量不改变原来的目录结构?{need-answer}

###gradle wrapper
在一个android工程下面执行
```
./gradlew
```
之后,就看到脚本在下载很多POM文件.
* 为什么要下这些文件?
* POM是什么文件?
* 下载到哪里了?为什么和android studo不共享?
```
 /home/wq1950/.gradle/wrapper/dists/gradle-2.10-bin/5unhgr46srqpi7bs0ei59tcoh1/gradle-2.10-bin.zip to /home/wq1950/.gradle/wrapper/dists/gradle-2.10-bin/5unhgr46srqpi7bs0ei59tcoh1
```

###遇到错误
```
Error:Cause: com/android/build/gradle/internal/model/DefaultAndroidProject : Unsupported major.minor version 52.0
```
这个时候通常要更新你的Android Studio版本.

###当你以cmake的方式用NDK时,你需要
* Android Studio 2.2, 可能需要最新的NDK

###gradle wrapper
在打开一个没有gradle wrapper的工程时,
android studio会帮你设置一个,但是它选的gradle版本号,你本地并不一定有.
没有的时候就囧了...它会去下载..

但是如果你留着这个gradle wrapper, 其他机器上导入这工程的时候, 又会遇到重新下载这个gradle的尴尬..

###Android Stduio使用的其他目录
* Windows
  * *C:\User\<UserName>\.android* android virtual device的目录
  * .AndroidStudioPreview2.2 配置目录
  * .gradle gradle相关的目录
* Linux
  

