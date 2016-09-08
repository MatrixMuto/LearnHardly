# Introduction
## App Fundamentals(应用基础知识)
Android SDK工具将代码资源编译到APK里.Android系统安装这个APK文件.

安装到设备后,每个应用在一个沙盒里:
为什么是个沙盒:
1. 多用户Linux系统,每个应用都是一个不同的用户. 
2. 用户ID, 应用文件权限, 用户ID才能访问.
3. 每个进程有自己的虚拟机(VM), 应用代码隔离
4. 默认情况,每个应用在自己的进程里,

Android系统, 最小权限原则.
应用不能访问系统中未被授权的部分.

如何与其他应用共享数据.
共享Linux用户ID,互相访问文件,同一进程,同一VM.(必须用相同的证书签名)
可以请求访问设备数据(用户的联系人,短信,SD卡,相机,蓝牙)

## Device Compatibility
## System Permissions

