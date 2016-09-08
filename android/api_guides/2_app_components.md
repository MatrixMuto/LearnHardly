#App Components
## Intent和Intent过滤器
Intent主要三种用途:
* 启动Activity
  - `startActivity()`
  - `startActivityForResult()`和`onActivityResult()` 
* 启动Service
  - `startService()`:启动服务执行一次性操作
  - `bindService()`:为了使用客户端-服务器接口
* 传递Broadcast
  - 接受系统广播
  - 发送广播给其他应用:`sendBroadcast()`,`sendOrderedBroadcast()`和`sendStickyBroadcast()`

* Intent类型
  两种类型:
  * 显式Intent: 按名称(完全限定类名)指定要启动的组件.
  * 隐式Intent: 不指定特定的组件, 声明要执行的常规操作.
* 使用PendingIntent
  PendingIntent是为了让外部程序使用被包含的Intent.像:
  - 当用户通过NotificationManager执行Intent时
  - 从主屏幕Widget执行Intent时
  - 从AlarmManager执行Intent时
  详细API可以看通知和Widget的API指南
  