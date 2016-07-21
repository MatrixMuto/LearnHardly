##Books，WebPage Link

##Tools
###ls
``` shell
 ls -h    #显示好读的文件大小
 ls -t    #按修改时间排序
 ls -S    #按文件大小
```
---
###grep
> 须看看AOSP中*source build/envsetup.sh*中,实现的脚本函数,*cgrep,jgrep*等等,里面用到了*grep,find*

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
