#Graphics architecture
> *note about [link](https://source.android.com/devices/graphics/architecture.html)*
> my highlight is [here](http://marker.to/tXzn5j)
##Tag
EGL, OpenGL ES, 

##
* [api doc Surface](https://developer.android.com/reference/android/view/Surface.html)
* [api doc SurfaceTexture](https://developer.android.com/reference/android/graphics/SurfaceTexture.html)

###第一,讲清楚BufferQueue和gralloc.
有可能迷糊到现在的原因,就是没搞清楚BufferQueue...

###EGL
* 首先讲最常用的接口吧,
    * [createWindowSurface](),
        在文档里是
        ```
        EGLSurface eglCreateWindowSurface(EGLDisplay dpy,EGLConfig config, EGLNativeWindowType win,const EGLint * attrib_list);
        ```
        在Android Java层是,
        ```java
        public static EGLSurface eglCreateWindowSurface (EGLDisplay dpy, EGLConfig config, Object win, int[] attrib_list, int offset)
        ```
        这里标记一下**offset参数**,后面需要展开EGLSurface, EGLDisplay, EGLConfig, win, arrtrib_list,这5个东西.

    * 以前找过ANativeWindow的实现, 很是难找.文档里讲了ANativeWindow
    * Java的*Surface*与C/C++里的*ANativeWindow*是可以划等号的.
    * ANativeWindow其实是BufferQueue Producer端的封装.
    * 而EGLSurface Window版本,就可以跟ANativeWindow划等号了.
    * ! []() platform/system/core include/system/window.h
        ``` c
        typedef struct ANativeWindow ANativeWindow;
        typedef struct ANativeWindow android_native_window_t;
        ```
    * 既然ANativeWindow是铁的Producer了,那么铁的Consumer有哪些,|SurfaceFlinger?|,|MediaCodec?|

* 一个概念是EGLConfig
* 类似key-value的性质,

###用了WebRTC里的EglBase14,EGLBase10,EGLBase的封装实现.
* EglBase.create
