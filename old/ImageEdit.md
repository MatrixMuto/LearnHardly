

AppBarLayout
[官方文档](http://developer.android.com/reference/android/support/design/widget/AppBarLayout.html)
AppBarLayout is a vertical LinearLayout which implements many of the features of material designs app bar concept, namely scrolling gestures.
** material designs app bar concept**
** scrolling gestures**


需求一：ToolBar需要能切换
之前采用了声明2个Toolbar，
然后手动设置Visibility来实现。


>xmlns:tools
>tools:context="XXXXX"
[Tools详解](http://www.jcodecraeer.com/a/anzhuokaifa/androidkaifa/2015/0309/2567.html)
[官方英文文档](http://tools.android.com/tech-docs/tools-attributes)
用来告诉android-studio如何预览xml的一套东西。


>xmlns:app
[stackoverflow的解答](http://stackoverflow.com/questions/26692233/what-is-the-app-android-xml-namespace)
意思是app内部自定义的属性（包括import进来的库）
例子是android:showAsAction和app:showAsAction，可以用来解决兼容性问题。