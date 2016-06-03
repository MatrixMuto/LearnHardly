---
layout: post
title:  "Android Work"
date:   2015-1-2 18:02:32 +0000
categories: Android Work
---


这次要做的界面，TitleBar，又叫ActionBar，有切换的需求。

ActionBar

ActionBar是可以通过style来实现，为啥。

Android Studio, Gradle
主要就是看懂build.gradle

Android Studio Color

[color-themes](http://color-themes.com/?view=index)可以下各种
>File>Import Settings...
[Monokai Sublime Text 3](http://color-themes.com/?view=theme&id=563a1a7680b4acf11273ae94)
这个里面有斜体···

[Sublime Text 2](http://color-themes.com/?view=theme&id=563a1a6380b4acf11273ae40)
这个导入会遇到Setting里显示不出来的问题。。
因为网站上本来就没写For Android Studio。。


建了一个5.1的BlankActivity

> compile 'com.android.support:appcompat-v7:23.1.1'
> compile 'com.android.support:design:23.1.1'

* AppCompatActivity
* android.support.design.widget.CoordinatorLayout
* android.support.design.widget.AppBarLayout
* android.support.design.widget.FloatingActionButton
* android.support.v7.widget.Toolbar
* android.support.design.widget.Snackbar


```java
    Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG).setAction("Action", null).show();
```
           
                        
>不懂
>xmlns:app="http://schemas.android.com/apk/res-auto"
>xmlns:tools="http://schemas.android.com/tools"

>不懂
>tools:context="com.example.muto.myapplication.MainActivity"

>style.xml、dimens.xml有两个，怎么选择的？

 
