###那些类型和头文件

###那些C语言们
http://stackoverflow.com/a/17209532

* K&R C, 1972-1989
* C89 or ANSI C, 1989-1990
* C90, 1990-1999
* C99, 1999-2011
* C11, 2011-

* GNU C, 默认并没有什么标准, Linux Kernel,


###c语言数据结构库
[回答](http://stackoverflow.com/questions/668501/are-there-any-open-source-c-libraries-with-common-data-structures)


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

---
###参数列表
__VA_ARGS__

int __android_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);


    return __android_log_write(prio, tag, buf);
}

#include <stdio.h>
#include <stdarg.h>


int
printf(const char *fmt, ...)
{
	int ret;
	va_list ap;


	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
	return (ret);
}


 va_start(ap, fmt);
应该解析fmt，到ap的列表，


vsnprintf
把(...)里实际的变量，根据ap的给事，最中转到输出到buf里


#define LOG_TAG "VariableSpeed"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
那这个宏又是什么意思。

const char *fmt, ...
和
__VA_ARGS__
是对应的

要想在这个宏里hook，怎么弄
找了个例子，
#define myprintf(...) printk("[lch]:File:%s, Line:%d, Function:%s," \  
     __VA_ARGS__, __FILE__, __LINE__ ,__FUNCTION__); 

这个例子里的宏替换又是个怎么替的。

后面的再研究

随便找了个blog
http://www.cnblogs.com/alexshi/archive/2012/03/09/2388453.html
这个宏是编译器内部的原理了。
从编译器的角度看。


va_list

###INT_MAX 和 INT_MIN
需要非常注意int类型的表示,overflow问题...
overflow是啥?
表达式的实际大小,超出了类型能表达的值.

###多维数组
int arr[10][10];
arr[row_index][col_index];
---
