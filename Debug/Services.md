#[Services](http://developer.android.com/guide/components/services.html)

Service是一个组件，在后台执行长时间的操作。
另一个App也可以启动service，service会继续在后台执行。
1. service可以是一个activit启动，通过startService()，一但启动了，即使activtiy销毁了，它也还存在。
service完成任务之后应该自我了结。
2. bound方式启动service bindService(),IPC,client-server
a bound service跟application组件一样长。
可以有多个组件一次bind service，但是当所有组件都unbind的时候，service就被销毁了。

service可以同时有上面2个特性。
onStartCommand()
onBind()

service可以声明成私有的

>service运行在主线程当中，service不会创建自己的线程，也不会运行在分开的进程中。
>你需要自己创建线程，避免ANR

用serice还是用线程。
就是看你是否需要在UI不存在的时候还要执行任务了。


service会被系统干掉，你自己用的时候小心。
```
android:exported="false"
```
只能自己的app用

service运行在声明它的app的进程的主线程里。默认。

Service  自己实现多线程的工作模式
IntentService，一个线程，一个工作队列，处理Intent one by one

#明天看下线程的模板代码

