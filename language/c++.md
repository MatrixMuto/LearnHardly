## virtual
```cpp
class IInterface : public virtual RefBase
```
* 不来不加virtual,就是公有继承...,
  public
  private
  protected
* 加个virtual,会有什么区别?
[StackOverflow](http://stackoverflow.com/a/21607)
多重继承时, 虚函数只保留一个实例?

## template是模板概念的一个标识符.

## const大法识符.

## const大法
``` c
const int a;
const int *b;
int* const c;
const int * const d;
```

constextp :　常量表达式

## 类内部中使用`static`时
使类成语与类本身相关,而不是与类对象相关。
- 修饰成员变量
- 修饰成员函数

## 类实例建立时,生成的指令流是怎么走的,内存模型又是怎么建立的?
- 成员变量的初始化?
- 类成员的构造函数
- 类自身的构造函数


## 类成员没有默认构造函数，所以不能用合成的默认构造函数。
```shell
rtmp.cpp:17:16: error: call to implicitly-deleted default constructor of 'RRtmpCli'
    return new RRtmpCli();
               ^
./rtmp.hpp:9:5: note: explicitly defaulted function was implicitly deleted here
    RRtmpCli() = default;
    ^
./rtmp.hpp:24:34: note: default constructor of 'RRtmpCli' is implicitly deleted because field 'socket' has no default constructor
    boost::asio::ip::tcp::socket socket;
```
``` c
const int a;
const int *b;
int* const c;
const int * const d;
```

constextp :　常量表达式

## 类内部中使用`static`时
使类成语与类本身相关,而不是与类对象相关。
- 修饰成员变量
- 修饰成员函数

## 类实例建立时,生成的指令流是怎么走的,内存模型又是怎么建立的?
- 成员变量的初始化?
- 类成员的构造函数
- 类自身的构造函数


## 类成员没有默认构造函数，所以不能用合成的默认构造函数。
```shell
rtmp.cpp:17:16: error: call to implicitly-deleted default constructor of 'RRtmpCli'
    return new RRtmpCli();
               ^
./rtmp.hpp:9:5: note: explicitly defaulted function was implicitly deleted here
    RRtmpCli() = default;
    ^
./rtmp.hpp:24:34: note: default constructor of 'RRtmpCli' is implicitly deleted because field 'socket' has no default constructor
    boost::asio::ip::tcp::socket socket;
```

## C++ throw相关

## boost regex

遇到的编译错误
undefined reference to `boost::basic_regex

-lboost_regex 

`boost::regex exrp( "^(?:http://)?([^/]+)(?:/?.*/?)/(.*)$" );`

^ 匹配字符串的开始位置
(?: exp) 匹配exp,不捕获匹配的文本，也不给此分组分配组号
? 0次或1次
([^/]+)除'/'外的字符一次或多次,组号有


## 头文件修改保存,不会触发make重新编译,怎么破?

## 加了`-g`选项,会生成debug信息...但实质上是在生成的文件(静态库,动态库,科执行)中添加饿了什么呢?