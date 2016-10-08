*2016.9.5 - 2016.9.11*

## 每CPU
多处理模型,有物理核,超线程技术的
每个CPU都有自己的runqueue

## ulimit
进程资源限制，「深入理解Linux内核」有讲。
`ulimit -c 1024`用来设置core文件的最大值，默认一般是0，所以没有core文件。
`gdb a.out core`可以让程序加载到段错误发生的状态。

## core文件
- 那core文件的结构，怎么生成的？
进程收到一个信号，信号的默认处理行为是`DUMP`，这个执行会把进程执行的上下文，保存到磁盘文件`core`中。
gdb工具可以用这个文件还原奔溃时的进程状态。

## 有哪些指令集？
- RISC
- Thumb
- SSE+

## 程序的编译和执行 
代码到汇编，汇编到目标文件，目标文件到可执行文件，可执行文件到进程。

## "boost/system/system_error.hpp:70"会Crash
```
boost::system::error_code error;
throw boost::system::system_error(error);

std::cerr << e.what() << std::endl;
```

## 怎么Debug进catch block?为什么要手动在Catch块中加断点,才会Debug进去?

## 哪里去找*boost system error_code.hpp* 里面 *system_category*的实现啊???它调的是std::system_category??

## `gdbserver`