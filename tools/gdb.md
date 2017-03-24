###breakpoint

###watch

###执行

## GDB可以反编译代码
```
gdb> disas main
```


### android gdb mediaserver

[Link](http://www.blogbus.com/cncoding-logs/170459529.html)

gdbserver :4800 –attach PID(上面查看的mediaserver的PID)

adb forward tcp:4800 tcp:4800

(gdb) set solib-absolute-prefix /<androidsrc>/out/target/product/generic/symbols/ 
(gdb) set solib-search-path /<androidsrc>/out/target/product/generic/symbols/system/lib/

target remote :4800

