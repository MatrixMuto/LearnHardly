*2016.8.1 - 2016.8.7*

###Linux下面,怎么方便的分析二进制数据?

###音频的丢包补偿技术,[Link](http://www.52im.net/thread-251-1-1.html)
* 发送端的丢包补偿
  * ![图](http://www.52im.net/data/attachment/forum/201604/23/130455smzvttseeztmpvpv.jpg)
  * 主动重传
  * 被动
    * FEC
    * 交织
* 接收端的丢包补偿
  * ![图](http://www.52im.net/data/attachment/forum/201604/23/130924z5xx519xpbkcjkbo.jpg)
  * 基于插入
  * 基于插值
  * 基于重构
  * ![错误隐藏技术的复杂度和质量关系](http://www.52im.net/data/attachment/forum/201604/23/131129pifaar8aerajae41.jpg)

###H.264数据组成结构?

* NAL unit分界,[Link](http://yumichan.net/video-processing/video-compression/introduction-to-h264-nal-unit/)
  * packet-trasport system, like RTP
  * Byte-stream system, 00000001 or 000001
* Slice
* Macro block
* access unit


###什么是NIO? [Netty3](http://netty.io/),Netty4,[MINA2](http://camel.apache.org/mina2.html)?
* [IBM教程](http://www.ibm.com/developerworks/cn/education/java/j-nio/index.html)
* JDK 1.4 引入的 NIO, 高速,面向块.

###TCP对于视频延迟有什么样的影响?

###shell有调试工具吗?


>NOTE:在cpp代码中,
```
#include "libavformat/avformat.h"
```
这样会导致链接错误, 因为头文件中的符号, 都会被当成C++的符号去解析.
