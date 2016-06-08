
###TODO:
重要的事:
- [ ] 通读[文档](http://nginx.org/en/docs/),要知道怎么找.
  1. - [ ] [A debugging log](http://nginx.org/en/docs/debugging_log.html)
  2. - [ ] [Logging to syslog](http://nginx.org/en/docs/syslog.html)

#Nginx-based Streaming Server

###配置HLS
* 参考网上的配置
  * [Setup Nginx on Ubuntu to Stream Live HLS Video](https://www.vultr.com/docs/setup-nginx-on-ubuntu-to-stream-live-hls-video)
> Note:Conf文件里所有路径都是服务器的绝对路径

###实时HLS的原理是什么?
  是想把推流上来的RTMP录制下来,来支持回放?