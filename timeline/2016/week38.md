*2016.9.19 - 2016.9.25*

## TODO
- port ffmpeg to RPi
- compile RPi kernel and flash
- qemu-system-arm work with gdb
- h.264
- rrtmp project
- libx264
- webrtc

## adlna stack
- `GetSelfIplist`飞
  在Linux上, 这个函数依赖`SIOCGIFCONF`, `SIOCGIFADDR`, `SIOCGIFNETMASK`获取IP和子网掩码
  - SIOCGIFCONF
  获取所有Interface的配置信息

- TVUPNP_EnableAutoMonitorNetIf

- ATVUPNPIfMonitor
  启动定时重复任务`UTaskManager`每2秒,会回调这个类的函数.
  收到消息时,相应改变全局的Ip地址管理类`WorkingIpAddrManager`


- UTaskManager NetIfMonitorTask
在DoInit中,获取IP列表
在DoRun中,也会获取Ip列表(调用`GetSelfIplist`)
将上一次的ip列表,与新获取的ip列表坐比对.

- WorkingIpAddrManager
在这个类中
Add和Remove会通知它的Listener关于Ip的改变消息

- Listener有哪些...
是通过
`MRESULT CtrlPoint::Start(MLong lSsdpPort)`

会调用
```
class MNetIfListener
{
public:
	virtual ~MNetIfListener(){};
	virtual MRESULT OnIfIpAdded (const MChar *szIpAddr, const MChar *szNetMask) = 0;
	virtual MRESULT OnIfIpRemoved (const MChar *szIpAddr, const MChar *szNetMask) = 0;
};
```

## 嵌入式板子连接Wi-Fi
[参考链接](https://www.olimex.com/forum/index.php?topic=3892.0)
- 加载Wi-Fi模块

  执行命令`insmod /lib/modules/marvell/mlan.ko`
  看到类似输出:
  ```
  mlan: module license 'Marvell Proprietary' taints kernel.
  Disabling lock debugging due to kernel taint
  ```
  执行命令`insmod /lib/modules/marvell/usb8xxx.ko`
  看到类似输出:
  ```
  wlan: Loading MWLAN driver
  VID/PID = 1286/2046, Boot2 version = 3201
  rx_work=1 cpu_num=2
  WLAN FW is active
  fw_cap_info=0x18ffa3, dev_cap_mask=0xffffffff
  wlan: version = USB8897-15.68.7.p69-C3X15C144-GPL-(FP68) 
  usbcore: registered new interface driver usb8xxx
  wlan: Driver loaded successfully
  ```
  检查mlan模块是否正常

  输入命令`ifconfig -a`
  看到类似输出:
  ```
  mlan0     Link encap:Ethernet  HWaddr 28:c2:dd:aa:dd:9b  
          BROADCAST MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

  ```
- 生成conf文件
  执行命令`wpa_passphrase SSID PASSPHRASE > abc.conf`
  SSID是Wi-Fi的名字
  PASSPHRASE是密码
- 连接WiFi
  
  执行命令:`wpa_supplicant -B -imlan0 -cabc.conf -Dwext`
  需要等上一会,会出现以下, 应该是连好了.
  `IPv6: ADDRCONF(NETDEV_CHANGE): mlan0: link becomes ready`

  检查SSID
  `iwconfig mlan0`
  如果能看到
  ```
  mlan0     IEEE 802.11-DS  ESSID:"Hotspot" [38]  
          Mode:Managed  Frequency=5.745 GHz  Access Point: E0:D1:73:28:7E:AB   
          Bit Rate:108 Mb/s   Tx-Power=15 dBm   
          Retry limit:9   RTS thr=2347 B   Fragment thr=2346 B   
          Encryption key:****-****-****-****-****-****-****-****   Security mode:open
          Power Management:on
          Link Quality=4/5  Signal level=-58 dBm  Noise level=-90 dBm
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:219434
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0
  ```
- 获取IP
  `udhcpc -i mlan0`
  类似输出:
  ```
  udhcpc (v1.22.1) started
  Sending discover...
  Sending select for 172.17.237.223...
  Lease of 172.17.237.223 obtained, lease time 43200
  /etc/udhcpc.d/50default: Adding DNS 202.101.172.35
```
  检查IP
  `ifconfig mlan0`
  看到类似输出: 则连上了
  ```
  mlan0     Link encap:Ethernet  HWaddr 28:c2:dd:aa:dd:9b  
          inet addr:172.17.237.223  Bcast:172.17.239.255  Mask:255.255.252.0
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:34 errors:0 dropped:0 overruns:0 frame:0
          TX packets:20 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:2630 (2.5 KiB)  TX bytes:2268 (2.2 KiB)
  ```
- 可以启动程序了

## 嵌入式板子怎么用gdb/gdbserver调试
- 一种是远程调试,Target上跑gdbserver,Host上跑`gdb`连过去
  `gdbserver`支持串口和TCP,估计TCP用的比较多
  在target上执行`gdbserver IP:PORT program`, 这样`gdbserver`就在监听状态了
  在host上,用cross-gdb去连上target
  `gdb`
  `gdb> target remote IP:PORT`
  但是还是没有debug符号~~

- 一种是直接在Target上跑gdb
  - 出错一:这个错误可能居然`continue`还能跑~
  ```
  (gdb) r
  Starting program: /usr/Federer/main_app/moldau.elf 
  warning: File "/lib/libthread_db-1.0.so" auto-loading has been declined by your `auto-load safe-path' set to "$debugdir:$datadir/auto-load".
  To enable execution of this file add
          add-auto-load-safe-path /lib/libthread_db-1.0.so
  line to your configuration file "/home/root/.gdbinit".
  To completely disable this security protection add
          set auto-load safe-path /
  line to your configuration file "/home/root/.gdbinit".
  For more information about this security protection see the
  "Auto-loading safe path" section in the GDB manual.  E.g., run from the shell:
          info "(gdb)Auto-loading safe path"
  warning: Unable to find libthread_db matching inferior's thread library, thread debugging will not be available.

  Program received signal SIGILL, Illegal instruction.
  0x764550e8 in ?? () from /lib/libcrypto.so.1.0.0
  ```
  - 问题:无法查看源代码~,所以还是推荐用`gdbserver`,但看看调用堆栈还是可以的.
