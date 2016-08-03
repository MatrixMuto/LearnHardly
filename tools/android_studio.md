> android studio是基于Intellij IDEA的,所以也会包括Intellij IDEA的内容.

###以前看过的,Android Studio的断点的高级技巧
* 加上不会中断的断点
* 不改代码加Log, 会输出到它的Console窗口
* 条件断点,还不会用

###在导入一个纯Java项目时,gradle文件怎么写,才能尽量不改变原来的目录结构..

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

###当你以cmake的方式用NDK时,你需要
* Android Studio 2.2, 可能需要最新的NDK