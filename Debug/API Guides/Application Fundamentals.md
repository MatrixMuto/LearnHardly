#[Application Fundamentals](http://developer.android.com/guide/components/fundamentals.html)

Once installed on a device, each Android app lives in its own security sandbox:

* The Android operating system is a multi-user Linux system in which each app is a different user.
* By default, the system assigns each app a unique Linux user ID (the ID is used only by the system and is unknown to the app). The system sets permissions for all the files in an app so that only the user ID assigned to that app can access them.
* Each process has its own virtual machine (VM), so an app's code runs in isolation from other apps.
* By default, every app runs in its own Linux process. Android starts the process when any of the app's components need to be executed, then shuts down the process when it's no longer needed or when the system must recover memory for other apps.

每个应用程序运行在一个安全沙盒中。
* Android操作系统是一个多用户Linux系统，每个app都是一个不同的用户。
* 默认情况，系统给每个app分配独立的Linux用户ID。系统把app的文件权限设置好，只有对应的用户ID才可以访问。
* 每个进程都有自己的VM，所以一个app的代码运行时是与其他app隔离的。
* 默认没人情况下，每个app运行自己的Linux进程用。当app中的任何模块需要被运行时，Android会启动进程。当app不再需要时，Android会结束进程，给其他app提供内存。

#App Components

1.四大组件如何使用?
四大组件是哪些：Activity、Service、Intent or Braodcast、ContentProvider
* Activity的特点是有交互界面，可以被其他组件启动。
* Service的特点是没有交互界面，长时间运行在后台，可以被启动和绑定（为了交互)。
* ContentProvider，通过CP，app可以读取和修改数据（前提是CP允许）。 ContentResolver
Anroid系统提供了一些CP，只要有相应的权限，就可以访问想应的数据。
App可以建立私有的CP,来存放数据。
>Android系统提供了哪些CP？
* Broadcast recivers是响应系统广播公告的组件。许多广播来自系统，例如，屏幕关闭了，低电池，拍了张新照片。
没有用户界面，可以发status bar notification。

Android系统设计独特的方面是，任何app都可以启动另一个app的组件。但是需要同过发Intent给Android系统。
>Therefore, unlike apps on most other systems, Android apps don't have a single entry point (there's no main() function, for example).

##Activating Components

There are separate methods for activating each type of component:
* You can start an activity (or give it something new to do) by passing an Intent to startActivity() or startActivityForResult() (when you want the activity to return a result).
* You can start a service (or give new instructions to an ongoing service) by passing an Intent to startService(). Or you can bind to the service by passing an Intent to bindService().
* You can initiate a broadcast by passing an Intent to methods like sendBroadcast(), sendOrderedBroadcast(), or sendStickyBroadcast().
* You can perform a query to a content provider by calling query() on a ContentResolver.


#The Manifest File
* Declaring components
* Declaring component capabilities
* Declaring app requirements

#App Resources
 * animations, menus, styles, colors, and the layout of activity
 * without modifying code 
 * optimize your app for a variety of device configurations 
 *  the SDK build tools define a unique integer ID
 *  the ability for you to provide alternative resources for different device configurations
 * supports many different qualifiers for your alternative resources
 