
##Steps
  1. get |MediaProjectionManager| via getSystemService 
  2. request Permission
  3. get |MedaProjection| via |MediaProjectionManager|
  4. 
  
```
android.media.projection.MediaProjectionManager
public android.content.Intent createScreenCaptureIntent()
Returns an Intent that must passed to startActivityForResult() in order to start screen capture. The activity will prompt the user whether to allow screen capture. The result of this activity should be passed to getMediaProjection.
```

```
android.media.projection.MediaProjection
public android.hardware.display.VirtualDisplay createVirtualDisplay(@android.support.annotation.NonNull java.lang.String name,
                                                                    int width,
                                                                    int height,
                                                                    int dpi,
                                                                    int flags,
                                                                    @android.support.annotation.Nullable android.view.Surface surface,
                                                                    @android.support.annotation.Nullable android.hardware.display.VirtualDisplay.Callback callback,
                                                                    @android.support.annotation.Nullable android.os.Handler handler)
Creates a VirtualDisplay to capture the contents of the screen.
Parameters:
name - The name of the virtual display, must be non-empty.
width - The width of the virtual display in pixels. Must be greater than 0.
height - The height of the virtual display in pixels. Must be greater than 0.
dpi - The density of the virtual display in dpi. Must be greater than 0.
flags - A combination of virtual display flags. See DisplayManager for the full list of flags.
surface - The surface to which the content of the virtual display should be rendered, or null if there is none initially.
callback - Callback to call when the virtual display's state changes, or null if none.
handler - The Handler on which the callback should be invoked, or null if the callback should be invoked on the calling thread's main android.os.Looper.
See Also:
VirtualDisplay
```

## 遇到的问题
* *createVirtualDisplay* 需要传入一个Surface,
但我不知道如何创建一个不需要显示的Surface,也不知道怎样获得其中的数据.
> [stackoverflow](http://stackoverflow.com/questions/26545970/take-a-screenshot-using-mediaprojection)

### TODO
- [ ] [grafika](https://github.com/google/grafika)
- [ ] [Graphics architecture](https://source.android.com/devices/graphics/architecture.html)


### MediaProjection Sample
[googlesamples/android-ScreenCapture](https://github.com/googlesamples/android-ScreenCapture)
```
git clone https://github.com/googlesamples/android-ScreenCapture.git
```