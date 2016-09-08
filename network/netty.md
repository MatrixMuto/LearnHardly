# Netty

## 类似的*技术?*
有mina, 知乎有人这么评价.[链接](https://www.zhihu.com/question/20527458)
新项目需要搭建一个纯java实现的的服务，因时间紧张决定先采用开源的框架先开发。目前了解的有mina和netty两个框架比较符合预期，查看了资料依然不好做出决定：
- mina比netty出现的早，都是Trustin Lee的作品；
- mina将内核和一些特性的联系过于紧密，使得用户在不需要这些特性的时候无法脱离，相比下性能会有所下降；netty解决了这个设计问题； 
- netty的文档更清晰，很多mina的特性在netty里都有； 
- netty更新周期更短，新版本的发布比较快； 
- 它们的架构差别不大，mina靠apache生存，而netty靠jboss，和jboss的结合度非常高，netty有对google 
- protocal buf的支持，有更完整的ioc容器支持(spring,guice,jbossmc和osgi)；
- netty比mina使用起来更简单，netty里你可以自定义的处理upstream events 或/和 downstream events，可以使用decoder和encoder来解码和编码发送内容；
- netty和mina在处理UDP时有一些不同，netty将UDP无连接的特性暴露出来；
- 而mina对UDP进行了高级层次的抽象，可以把UDP当成"面向连接"的协议，而要netty做到这一点比较困难。
- mina把TCP和UDP一样当"有连接"的处理，一个UDP请求会按照address产生一个新的IoSession，过期时间是1分钟，这样做的好处是显然的，但是对于有性能要求的项目就不好了，对一个无连接的东西cache 1分钟，大多数时候可能是白cache了，做无用功。
- Mina这样做可能还有个初衷是连续解码用的，比如一个包太大了，分了两次传输；但是这样的设计应该是udp大忌了。

