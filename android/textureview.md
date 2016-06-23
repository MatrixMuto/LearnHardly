###TextureView中, View的这两个函数是在什么时机被调用的?
```java
    @Override
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();

        if (!isHardwareAccelerated()) {
            Log.w(LOG_TAG, "A TextureView or a subclass can only be "
                    + "used with hardware acceleration enabled.");
        }

        if (mHadSurface) {
            invalidate(true);
            mHadSurface = false;
        }
    }

    /** @hide */
    @Override
    protected void onDetachedFromWindowInternal() {
        destroySurface();
        super.onDetachedFromWindowInternal();
    }
```
* final和subclass, 加了final, subclass就无法override?
```java
    /**
     * Subclasses of TextureView cannot do their own rendering
     * with the {@link Canvas} object.
     *
     * @param canvas The Canvas to which the View is rendered.
     */
    @Override
    public final void draw(Canvas canvas) {
        // NOTE: Maintain this carefully (see View.java)
        mPrivateFlags = (mPrivateFlags & ~PFLAG_DIRTY_MASK) | PFLAG_DRAWN;

        applyUpdate();
        applyTransformMatrix();
    }

    /**
     * Subclasses of TextureView cannot do their own rendering
     * with the {@link Canvas} object.
     *
     * @param canvas The Canvas to which the View is rendered.
     */
    @Override
    protected final void onDraw(Canvas canvas) {
    }
```

###成员HardwareLayer,
```java
/**
 * A hardware layer can be used to render graphics operations into a hardware
 * friendly buffer. For instance, with an OpenGL backend a hardware layer
 * would use a Frame Buffer Object (FBO.) The hardware layer can be used as
 * a drawing cache when a complex set of graphics operations needs to be
 * drawn several times.
 *
 * @hide
 */
final class HardwareLayer {
    ...
}
```
* 这时候创建的SurfaceTexture并没有和GLES绑定,那在什么时候绑定呢?
* 肯定不需要外面的接口,那就是看mSurface传到哪里了?
* 
```java
    private HardwareLayer mLayer;

    @Override
    HardwareLayer getHardwareLayer() {
        // NOTE: Maintain these two lines very carefully (see View.java)
        mPrivateFlags |= PFLAG_DRAWN | PFLAG_DRAWING_CACHE_VALID;
        mPrivateFlags &= ~PFLAG_DIRTY_MASK;

        if (mLayer == null) {
            if (mAttachInfo == null || mAttachInfo.mHardwareRenderer == null) {
                return null;
            }

            mLayer = mAttachInfo.mHardwareRenderer.createTextureLayer();
            if (!mUpdateSurface) {
                // Create a new SurfaceTexture for the layer.
                mSurface = new SurfaceTexture(false);
                mLayer.setSurfaceTexture(mSurface);
            }
            mSurface.setDefaultBufferSize(getWidth(), getHeight());
            nCreateNativeWindow(mSurface);

            mSurface.setOnFrameAvailableListener(mUpdateListener, mAttachInfo.mHandler);

            if (mListener != null && !mUpdateSurface) {
                mListener.onSurfaceTextureAvailable(mSurface, getWidth(), getHeight());
            }
            mLayer.setLayerPaint(mLayerPaint);
        }

        if (mUpdateSurface) {
            // Someone has requested that we use a specific SurfaceTexture, so
            // tell mLayer about it and set the SurfaceTexture to use the
            // current view size.
            mUpdateSurface = false;

            // Since we are updating the layer, force an update to ensure its
            // parameters are correct (width, height, transform, etc.)
            updateLayer();
            mMatrixChanged = true;

            mLayer.setSurfaceTexture(mSurface);
            mSurface.setDefaultBufferSize(getWidth(), getHeight());
        }

        applyUpdate();
        applyTransformMatrix();

        return mLayer;
    }
```