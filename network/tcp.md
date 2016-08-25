## 关键词
- ISN: Initial Seq Number.
- SEQ:TCP头部,32bit. 在建立连接时,它的值等于ISN+1. 表示当前Packet的中的起始字节序列号.
  - 连接建立的SYN包会占用一个序号
- ACK:表示期望收到的下一个字节序号 
  - 连接结束的ACK会占用一个序号
- TCP头部并没有数据长度
- TCP头部长度是用4个bit来. 表示有多少个32bit单元.
- TCP头部有6个标志位. SYN,ACK,URG,RST,

## TCP Tunnel
- 涉及到的知识点是NAT和TCP同时打开.
- NAT有四种类型:
  1. 端口, IP 