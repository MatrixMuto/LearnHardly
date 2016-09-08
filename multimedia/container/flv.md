*FLV在RTMP中用到*
[文档]()

###FLV文件结构
HEADER
TAG0len
TAG1
TAG1len
TAGn
TAGnlen
* Header
  
* TAG可以是Video Tag
  :一个字节, 高4位表示(关键帧,中间帧,...), 低4位表示Codec,(7:AVC)
  TAG DATA:
* TAG可以是Audio Tag
