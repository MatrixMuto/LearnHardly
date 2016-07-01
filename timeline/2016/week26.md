*[Week 26	June 27, 2016	July 3, 2016](http://www.epochconverter.com/weeks/2016)*
##近期的目标
* 希望能在Andoird端实现一个Broadcaster.
* 希望能吃透grafika
* 希望能吃透ExoPlayer
* 希望能吃透FFmpeg
* 希望能吃透rtmp
* 希望能吃透nginx-rtmp

###为什么会发生Rebuffer?

###ExoPlayer的启动播放过程的线程时序图

###比方说我要实现一个快速显示画面的功能?
* 期望的延迟?
* 有哪些方案可以选择

###比方说,我要做实时会话(RTC),应该怎么做?
* 实时会话的延迟一般是多少? 400ms? 比方说微信音频聊天,怎么测试这个延迟?
* 

###你要学熟悉哪个框架?(WebRTC,FFmpeg,ExoPlayer)
* 对于项目所采用的框架熟不熟
* 对框架的通用的要点的理解与掌握

###ExoPlayer播放HLS的时候, HLS的分辨率变化的时候, 它怎么播放的?

###ExoPlayer中用到了android.os.Trace, 
```java
  @TargetApi(18)
  private static void beginSectionV18(String sectionName) {
    android.os.Trace.beginSection(sectionName);
  }

  @TargetApi(18)
  private static void endSectionV18() {
    android.os.Trace.endSection();
  }
```
什么用处呢?

###写一个直播上传端的话,可以参考ExoPlayer的线程模型(doSomeWork)吗?
为什么ExoPlayer可以用doSomeWork的方式来调度?

###Choreographer是什么?

###GLES20.glGenFramebuffers这个Framebuffer是什么?
```java
// Create framebuffer object and bind it.
GLES20.glGenFramebuffers(1, values, 0);
GlUtil.checkGlError("glGenFramebuffers");
mFramebuffer = values[0];    // expected > 0
GLES20.glBindFramebuffer(GLES20.GL_FRAMEBUFFER, mFramebuffer);
GlUtil.checkGlError("glBindFramebuffer " + mFramebuffer);
```

###|MediaRecorder|用Camera和我们自己用Camera有什么区别?
###怎么录4K视频?

###GLSurfaceView?
>The GLSurfaceView class provides some helper classes that help manage EGL contexts, inter-thread communication, and interaction with the Activity lifecycle.
That's is. You do not need to use a GLSurfaceView to use GLES.
```
public interface Renderer { 
{
    void onSurfaceCreated(GL10 gl, EGLConfig config);
    void onSurfaceChanged(GL10 gl, int width, int height);
    void onDrawFrame(GL10 gl);
}
```