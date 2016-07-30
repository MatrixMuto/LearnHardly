
##最近
* grafika
  * 理解EGLSurface?Surface?ANativeWindow?
  * libgui, libui
* ffmpeg
* ExoPlayer
* rtmp, flv
* H.264 x264
* Android Broadcaster
* PPT

###CSDN大牛-雷肖华
[CSDN大牛-雷肖华](http://blog.csdn.net/leixiaohua1020)
[hanwei_1049](http://blog.chinaunix.net/uid/13746440.html)
[win_lin](http://my.csdn.net/winlinvip) //这人...

###Docker是什么?
[深入浅出Docker（一）：Docker核心技术预览](http://www.infoq.com/cn/articles/docker-core-technology-preview)
* Docker提供了一种在安全、可重复的环境中自动部署软件的方式
* ![Containers vs VMs](http://cdn3.infoqstatic.com/statics_s1_20160712-0252u2/resource/articles/docker-core-technology-preview/zh/resources/0731013.jpg)

##dumpcache
[dumpcache-服务器领域](http://www.dumpcache.com/wiki/doku.php?id=start)

###导入Jar包后,编译报错.
>Error:Execution failed for task ':app:transformResourcesWithMergeJavaResForDebug'.
> com.android.build.api.transform.TransformException: com.android.builder.packaging.DuplicateFileException: Duplicate files copied in APK META-INF/license.txt
  	File1: /home/muto/.gradle/caches/modules-2/files-2.1/org.springframework.android/spring-android-core/2.0.0.M3/c7e2c60943248bbce5de6cf552592281ed2296b/spring-android-core-2.0.0.M3.jar
  	File2: /home/muto/.gradle/caches/modules-2/files-2.1/org.springframework.android/spring-android-rest-template/2.0.0.M3/204c594c2a47073b30d3cb14ca69ba1066c4e44c/spring-android-rest-template-2.0.0.M3.jar
原因翻译自[StackOverflow](http://stackoverflow.com/a/27989570)    
  Android Gradle 严格不允许重复文件.
后来发现文档有写
```
    packagingOptions {
        exclude 'META-INF/ASL2.0'
        exclude 'META-INF/LICENSE'
        exclude 'META-INF/license.txt'
        exclude 'META-INF/NOTICE'
        exclude 'META-INF/notice.txt'
    }
```


###新的assert文件怎么加?
