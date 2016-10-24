
## 搭一个外网环境的服务器,使得连一个LAN的两个Android设备, 能互相通话.
- webrtc-android中有AppRTCDemo, 但是它用的服务器地址是被墙的,
- AppRTCDemo是可以用浏览器的直接WebRTC的.
- 那个服务器器代码是开源的. 放到内网上应该问题不大?
  [repo地址](https://github.com/webrtc/apprtc)
  - 这网站需要框架和服务器~
  >Running AppRTC locally requires the Google App Engine SDK for Python and Grunt.
  - 这个网站需要一定`turnserver`

- turn server
  [rfc5766-turn-server](https://github.com/coturn/rfc5766-turn-server)
  [coturn](https://github.com/coturn/coturn)
  
## 搭建AppRTCDemo服务
按照Repo的指导搭一遍
- [Google Cloud SDK](https://cloud.google.com/sdk/docs/)安装
  


## Step-05必须要HTTPS, SSL了.. 
- 虽然StartSSL是免费的, 但是域名相关, 先自己生成一个看看能不能用...
