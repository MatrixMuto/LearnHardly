*2016.8.8 - 2016.8.14*

###打开RTMP流之后,video codec的extradata究竟是啥样的,AVPacket.data也究竟是什么格式的?

###AVPacket中的data, video可能有多个NALU.

###rtsp
rtsp://218.204.223.237:554/live/1/66251FC11353191F/e7ooqwcfbqjoo80j.sdp

###AR
- 基本是靠免费的SDK试验..还不一定开源,总之是一大坑.

###内存对齐??
- 下面的宏

```c
#define ngx_align(d, a)     (((d) + (a - 1)) & ~(a - 1))
#define ngx_align_ptr(p, a)                                                   \
    (u_char *) (((uintptr_t) (p) + ((uintptr_t) a - 1)) & ~((uintptr_t) a - 1))
```
