#Adobe's Real Time Messaging Protocol
[intro](http://blogs.adobe.com/ktowes/2009/06/rtmp_specification_now_availab.html)



##5.4. Protocol Control Messages
RTMP Chunk Steam uses message type IDs, 1, 2, 3, 5, and 6 for protocol control messages.
These messages contain information needed by them RTMP Chunk Steam protocol.
These protocol control messages **MUST** have message stream ID 0 and be sent in chunk stream ID 2.
Protocol control messages take effect as soon as they are received;
their timestamps are ignored.
###5.4.1. Set Chunk Size
notify the peer of a new maximum chunk size.
defaults to 128 bytes; SHOULD at least 128byte; MUST at least 1 byte;
0 bit MUST be zero.
Valid sizes are 1 to 0x7FFFFFFF; but no message is alrger then 0xFFFFFF;
###5.4.2. 
###5.4.3. 
###5.4.4. Window Acknowledgement Size (5)
The *client* or the *server* sends this message to inform the peer of the window size to use between sending acknowledgments.
Thre sender **expects acknowledgment** from ite peer after the sender sends window size bytes. 


##看协议遇到的问题,不知道去哪找FCPublish的Spec.
原来是AS3的接口.

##里面的一些概念还是不太清楚.
照着抓的包看,倒是能看懂一些,也知道要从AS3的东西

###Client时,C0就等与3,C1是1536 octets long.

###Client(直播)与Server之间的流程
* 协商哪些属性?
  * app name
　* key?
  * swfurl?

###Client(播放)与Server之间的流程
* 协商哪些属性?

###Server怎么把Client(直播)的Chunk,推给Client(播放)的?
Server会支持一些功能(转码,转Container,...)
* 负载均衡?尽量让edge去消化请求?
* Server需要存app的名字,还要根据Key给Client给转发

###为什么比HLS延迟好?

###坑,Basic Header中的Chunk Stream ID是什么规则...


###releaseStream是不是一定要调用?

###FCPublish是什么作用,是不是一定要调用?

###发了@setDataFrame|onMetaData,居然是因为chunksize太大...
总结:需要去看Server Log来确定问题..

