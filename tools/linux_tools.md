##Books，WebPage Link

##Tools
###ls
``` shell
 ls -h    #显示好读的文件大小
 ls -t    #按修改时间排序
 ls -S    #按文件大小
```
---
## grep
> 须看看AOSP中*source build/envsetup.sh*中,实现的脚本函数,*cgrep,jgrep*等等,里面用到了*grep,find*

- grep 指定类型(后缀)的文件
  `grep --include \*.cpp`
---
###netstat
  > netstat - Print network connections, routing tables, interface statistics, masquerade connections, and multi‐cast memberships

  * 显示有几个interface
  ```
  netstat -i
  ```

  * 只显示TCP/IP v4 协议簇的.
  ```
  netstat --inet --inet6
  ```

  * 只显示监听状态的连接
  ```
  netstat -l
  ```

  * 不去解析ip和port
  ```
  nestat -n
  ```
  > --numeric , -n
        Show numerical addresses instead of trying to determine symbolic host, port or user names. 

###tail
> tail - output the last part of files
  tail -f

###tree
* 显示?层结构
```
tree -L 1 <DIR>
```

###tcpdump
[androidtcpdump](http://www.androidtcpdump.com/)

```
tcpdump -i lo tcp port 1935 -w /tmp/001-unnamed.pcap
```

###ldd
> ldd - print shared library dependencies
```
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fb4c7705000)
	libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007fb4c7500000)
	/lib64/ld-linux-x86-64.so.2 (0x000055923f642000)
```

###lsof
* 找端口号对应的进程
  ```
  ls -i TCP
  ls -i TCP:1935
  ```
  像看nginx进程的话,需要加上sudo

## curl
- 设置代理既可以通过命令行,也可以通过~/.curlrc配置文件.
  配置文件里设置的话, 把选项转换一下就好
  ```
  socks5-hostname = 127.0.0.1:1080
  ```
  等价于`curl --socks5-hostname 127.0.0.1"
