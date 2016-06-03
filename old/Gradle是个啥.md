#Build System Overview
啥都先从官网的文档看起，首先这个主题的总览 [Build System Overview](http://developer.android.com/sdk/installing/studio-build.html)

[干货图](http://developer.android.com/images/build.png)


> If different folders contain resources with the same name or setting, the following override priority order is: dependencies override build types, which override product flavors, which override the main source directory.
* The Android Asset Packaging Tool (aapt) takes your application resource files, such as the AndroidManifest.xml file and the XML files for your Activities, and compiles them. An R.java is also produced so you can reference your resources from your Java code.
* The aidl tool converts any .aidl interfaces that you have into Java interfaces.
* All of your Java code, including the R.java and .aidl files, are compiled by the Java compiler and .class files are output.
* The dex tool converts the .class files to Dalvik byte code. Any 3rd party libraries and .class files that you have included in your module build are also converted into .dex files so that they can be packaged into the final .apk file.
* All non-compiled resources (such as images), compiled resources, and the .dex files are sent to the apkbuilder tool to be packaged into an .apk file.
* Once the .apk is built, it must be signed with either a debug or release key before it can be installed to a device.
* Finally, if the application is being signed in release mode, you must align the .apk with the zipalign tool. Aligning the final .apk decreases memory usage when the application is -running on a device.

#[Configuring Gradle Builds](http://developer.android.com/tools/building/configuring-gradle.html)
从官方文档看下来，会比较全面，很多还用不太刀


#[Android Plugin for Gradle](http://developer.android.com/tools/building/plugin-for-gradle.html)
Android build system包含一个为了用Gradle而写的Android插件。
Gradle是一个高级的构建工具，管理依赖库，允许你自定义构建逻辑。
Android Studio用了一个Gradle wrapper来全面的集成Android plugin For Gradle。
Android plugin For Gradle也可以独立运行，所以你可以用命令行方式来编译项目，而不用装Android Studio。
不管你用什么方式构建，所有生成的东西都是一样的。

##Build Configuration
项目配置定义在build.gradle文件里，纯文本文件，用到了Gradle和Android plugin语法。
定义了一下几个方面的内容：
* Build variants.
* Dependencies. 这样你就不用从自己下载依赖库，
* Manifest entries. generate multiple APKs
* Signing. 
* ProGuard.
* Testing. 

总结：Gradle build files use Domain Specific Language (DSL) to describe and manipulate the build logic through Groovy syntax. Groovy is a dynamic language that you can use to define custom build logic and to interact with the Android-specific elements provided by the Android plugin for Gradle.

##Build by Convention

##Project and Module Settings
  ###Project Build File
  ###Module Build File
##Dependencies
* Module Dependencies
* Local Dependencies
* Remote Dependencies

##Build Tasks
* assemble
* check
* build
* clean

##Gradle Wrapper
* A JAR file
* A properties file
* A shell script for Windows platforms
* A shell script for Mac and Linux platforms

##Build Variants

