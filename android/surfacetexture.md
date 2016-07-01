
##SurfaceTexture single buffer mode
```java
/**
 * Captures frames from an image stream as an OpenGL ES texture.
 *
 * <p>The image stream may come from either camera preview or video decode. A
 * {@link android.view.Surface} created from a SurfaceTexture can be used as an output
 * destination for the {@link android.hardware.camera2}, {@link android.media.MediaCodec},
 * {@link android.media.MediaPlayer}, and {@link android.renderscript.Allocation} APIs.
 * When {@link #updateTexImage} is called, the contents of the texture object specified
 * when the SurfaceTexture was created are updated to contain the most recent image from the image
 * stream.  This may cause some frames of the stream to be skipped.
 *
 * <p>A SurfaceTexture may also be used in place of a SurfaceHolder when specifying the output
 * destination of the older {@link android.hardware.Camera} API. Doing so will cause all the
 * frames from the image stream to be sent to the SurfaceTexture object rather than to the device's
 * display.
 *
 * <p>When sampling from the texture one should first transform the texture coordinates using the
 * matrix queried via {@link #getTransformMatrix(float[])}.  The transform matrix may change each
 * time {@link #updateTexImage} is called, so it should be re-queried each time the texture image
 * is updated.
 * This matrix transforms traditional 2D OpenGL ES texture coordinate column vectors of the form (s,
 * t, 0, 1) where s and t are on the inclusive interval [0, 1] to the proper sampling location in
 * the streamed texture.  This transform compensates for any properties of the image stream source
 * that cause it to appear different from a traditional OpenGL ES texture.  For example, sampling
 * from the bottom left corner of the image can be accomplished by transforming the column vector
 * (0, 0, 0, 1) using the queried matrix, while sampling from the top right corner of the image can
 * be done by transforming (1, 1, 0, 1).
 *
 * <p>The texture object uses the GL_TEXTURE_EXTERNAL_OES texture target, which is defined by the
 * <a href="http://www.khronos.org/registry/gles/extensions/OES/OES_EGL_image_external.txt">
 * GL_OES_EGL_image_external</a> OpenGL ES extension.  This limits how the texture may be used.
 * Each time the texture is bound it must be bound to the GL_TEXTURE_EXTERNAL_OES target rather than
 * the GL_TEXTURE_2D target.  Additionally, any OpenGL ES 2.0 shader that samples from the texture
 * must declare its use of this extension using, for example, an "#extension
 * GL_OES_EGL_image_external : require" directive.  Such shaders must also access the texture using
 * the samplerExternalOES GLSL sampler type.
 *
 * <p>SurfaceTexture objects may be created on any thread.  {@link #updateTexImage} may only be
 * called on the thread with the OpenGL ES context that contains the texture object.  The
 * frame-available callback is called on an arbitrary thread, so unless special care is taken {@link
 * #updateTexImage} should not be called directly from the callback.
 */
public class SurfaceTexture {
    ...
    /**
     * Construct a new SurfaceTexture to stream images to a given OpenGL texture.
     *
     * In single buffered mode the application is responsible for serializing access to the image
     * content buffer. Each time the image content is to be updated, the
     * {@link #releaseTexImage()} method must be called before the image content producer takes
     * ownership of the buffer. For example, when producing image content with the NDK
     * ANativeWindow_lock and ANativeWindow_unlockAndPost functions, {@link #releaseTexImage()}
     * must be called before each ANativeWindow_lock, or that call will fail. When producing
     * image content with OpenGL ES, {@link #releaseTexImage()} must be called before the first
     * OpenGL ES function call each frame.
     *
     * @param texName the OpenGL texture object name (e.g. generated via glGenTextures)
     * @param singleBufferMode whether the SurfaceTexture will be in single buffered mode.
     *
     * @throws Surface.OutOfResourcesException If the SurfaceTexture cannot be created.
     */
    public SurfaceTexture(int texName, boolean singleBufferMode) {
        mCreatorLooper = Looper.myLooper();
        nativeInit(false, texName, singleBufferMode, new WeakReference<SurfaceTexture>(this));
    }
    
    /**
     * Construct a new SurfaceTexture to stream images to a given OpenGL texture.
     *
     * In single buffered mode the application is responsible for serializing access to the image
     * content buffer. Each time the image content is to be updated, the
     * {@link #releaseTexImage()} method must be called before the image content producer takes
     * ownership of the buffer. For example, when producing image content with the NDK
     * ANativeWindow_lock and ANativeWindow_unlockAndPost functions, {@link #releaseTexImage()}
     * must be called before each ANativeWindow_lock, or that call will fail. When producing
     * image content with OpenGL ES, {@link #releaseTexImage()} must be called before the first
     * OpenGL ES function call each frame.
     *
     * Unlike {@link #SurfaceTexture(int, boolean)}, which takes an OpenGL texture object name,
     * this constructor creates the SurfaceTexture in detached mode. A texture name must be passed
     * in using {@link #attachToGLContext} before calling {@link #releaseTexImage()} and producing
     * image content using OpenGL ES.
     *
     * @param singleBufferMode whether the SurfaceTexture will be in single buffered mode.
     *
     * @throws Surface.OutOfResourcesException If the SurfaceTexture cannot be created.
     * @hide
     */
    public SurfaceTexture(boolean singleBufferMode) {
        mCreatorLooper = Looper.myLooper();
        nativeInit(true, 0, singleBufferMode, new WeakReference<SurfaceTexture>(this));
    }
    ...
}
```
