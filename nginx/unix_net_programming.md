###首先是Socket Address Structures

sockaddr_

我的这个Ubuntu版本是一下这样的..
//in /usr/include/<netinet/in.h>
```c


/* Structure describing an Internet socket address.  */
struct sockaddr_in
  {
    __SOCKADDR_COMMON (sin_);
    in_port_t sin_port;                 /* Port number.  */
    struct in_addr sin_addr;            /* Internet address.  */

    /* Pad to size of `struct sockaddr'.  */
    unsigned char sin_zero[sizeof (struct sockaddr) -
                           __SOCKADDR_COMMON_SIZE -
                           sizeof (in_port_t) -
                           sizeof (struct in_addr)];
  };
```


###地址的处理是第一块内容
* inet_pton
* getaddrinfo
* gethostbyname

###API
* socket,
* bind,
* listen,
* connect,
* send,
* recv,
* shutdown,
* *close*


###TCP选项
