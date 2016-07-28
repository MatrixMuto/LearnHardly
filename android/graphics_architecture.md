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

###为什么把SurfaceView的Surface,用来创建EglSurface之后,Camera就不能用这个Surface了??
camera 的 *setPreviewDisplay* 接口会出现IOException
```
W/System.err: java.io.IOException: setPreviewTexture failed
W/System.err:     at android.hardware.Camera.setPreviewDisplay(Native Method)
```
恐怕得弄请出
```java
    eglSurface = EGL14.eglCreateWindowSurface(eglDisplay, eglConfig, surface, surfaceAttribs, 0);
```
这行代码的实现了.
原因可能是..
* 调用过这个接口之后,是调用了NativeWindow的什么接口..导致Camera就不能使用这个NativeWindow了.

说到底,找Camera的时候,接口都那么不好找,说明它的框架我还不熟啊...


###android的egl就是ANativeWindow啊...


###grafika中,camera和mediacodec结合的例子
* 用GLSurfaceView,在onSurfaceCreated时, GLSurfaceView内部的EGLContext里, 创建了一个texture,并绑定给|mSurfaceTexture|.
  有了|SurfaceTexture|之后,就打开|mCamera|,注册|onFrameAvaliable|,设置给它.在Camera更新时,请求GLSurfaceView的requestRender.
  触发|onDrawFrame|,
  SurfaceTexture的|updateTexImage|,从里头拿最新的Frame,更新到本地的Context里?
  |TextureMovieEncoder|里头有新的线程和新的Context,并且使用|VideoEncoderCore|,来做Encode的事情.
  最后,调用GLES的接口,把SurfaceTexture的内容Render出来.
* 使用了|SurfaceView|,在|surfaceCreated|回调里, 首先,从这个SurfaceView的Surface,绑定一个|mDisplaySurface|,在这个|EGLSurface|上下文里,
  创建一个|texture|,并绑定到|mCameraTexture|.
  设置camera的previewTexture,|startpreview|.
  TODO:这里又创建了|mEncoderSurface|,是从|MediaCodec|的|createInputSurface|,这里也用了WindowSurface.
  根本上,都是EGL.createWindowSurface,和createPbuffer.这之间的区别是什么???
  然后等的就是|onFrameAvailable|,但是它是向UI thread的发的消息,去调用OpenGL的接口.
* TextureFromCameraActivity
  |SurfaceView|完全与|RenderHandlerThread|独立开的一种模型.

##makeCurrent和swapBuffer是什么鬼?

