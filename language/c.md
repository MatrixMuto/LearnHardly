###那些类型和头文件

###那些C语言们
http://stackoverflow.com/a/17209532

* K&R C, 1972-1989
* C89 or ANSI C, 1989-1990
* C90, 1990-1999
* C99, 1999-2011
* C11, 2011-

* GNU C, 默认并没有什么标准, Linux Kernel,

###<stdint.h>
```c
/* Types for `void *' pointers.  */
#if __WORDSIZE == 64
# ifndef __intptr_t_defined
typedef long int		intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned long int	uintptr_t;
#else
# ifndef __intptr_t_defined
typedef int			intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned int		uintptr_t;
#endif
```

###<netinet/in.h>
```c
#include <features.h>
#include <stdint.h>
#include <sys/socket.h>
#include <bits/types.h>
```

###<sys/types.h>定义了什么?

```c
#include <bits/types.h>

#ifdef	__USE_BSD
# ifndef __u_char_defined
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
#  define __u_char_defined
# endif
#endif
```

###为什么要这么来用这些类型?能解决什么跨平台的问题吗?
比如ngx_int_t,u_char等.

###size_t



##Compiler
* gcc
* arm-linux-androidabi-gcc

###strict-aliasing
在编译ffmpeg的android版本的时候,编译选项里有一个-Werror=strict-aliasing,[这个是stackoverflow的解答](http://stackoverflow.com/questions/98650/what-is-the-strict-aliasing-rule)

