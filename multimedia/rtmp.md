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