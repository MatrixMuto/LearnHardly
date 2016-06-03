需求：导入一个native-lib

随便在工程目录加了这么一个目录
jnilibs/armeabi/libxxx.so

却遇到了这么一个问题：
01-16 15:20:10.838 23170-23170/com.arcsoft.galleryforintel E/EngineController: Unsatisfied Link error: java.lang.UnsatisfiedLinkError: dalvik.system.PathClassLoader[DexPathList[[zip file "/data/app/com.arcsoft.galleryforintel-1.apk"],nativeLibraryDirectories=[/data/app-lib/com.arcsoft.galleryforintel-1, /vendor/lib, /system/lib]]] couldn't find "libPhotoEditJNI.so"

通过解压APK发现，我的库是单独在一个armeabi目录里，同时存在一个armeabi-v7a的目录。
做了一下尝试，把我建的目录改成armeabi-v7a，居然就能load了。

为什么放在armeabi目录的时候会无法找到，
找的过程是从app-lib下找，
也就是为什么没有被copy到app-lib里，
**也就是说apk里的libs有多个目录，而android是基于什么规则去加载的?**

这是一个apk安装过程来解释这个事情，
[Android 4.4(KitKat)中apk包的安装过程](http://blog.csdn.net/jinzhuojun/article/details/25542011)
干货，直接上代码看的。。

还有一个原因是我的apk下面还有一些别的libs，应该是我的那些依赖包里加进来的。
有这些
libblasV8.so
librsjni.so
libRSSupport.so

**它们是什么过程加进来的**

