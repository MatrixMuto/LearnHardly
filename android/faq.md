###权限
*看个总结性的文章吧...*
* 哪个版本之后必须申请权限，否则会有什么问题？
* 哪些权限是需要申请的?
* 哪些办法处理权限?
  强行设置API LEVEL?
* 申请权限的代码怎么写?注意什么?
  在Activity/Fragment里面?


###API方面的兼容性
* *@TargetApi(23)*这个注解可以放在成员函数声明之前,
  问题是还可以放在哪些地方,有什么作用?
  > Indicates that Lint should treat this type as targeting a given API level, no matter what the project target is.

  那Lint的作用又是什么?

  [参考](http://www.360doc.com/content/14/1113/09/11800748_424743381.shtml)

*　Gradle配置里,compileSdkVersion, buildToolsVersion, minSdkVersion, targetSdkVersion,这些都起什么作用?
```
   compileSdkVersion 23
    buildToolsVersion "23.0.1"

    defaultConfig {
        minSdkVersion 16
        targetSdkVersion 23
    }
```


###savedInstanceState
什么时候,Activiy/Fragment的onCreate回调的savedInstanceState会有东西取?
