###Eclipse各版本
Neon ()
Mars (4.5.2)
Luna

### Eclipse CDT安装,[Link](https://eclipse.org/cdt/downloads.php)
其实最好是下载配置好的Eclipse+CDT安装包.

### 装了新的Eclipse包,全集成的.

### 怎么告诉一个Project, Linux系统本身的头文件?
因为SDL是个单独的目录,
```
#include <SDL.h>
#include <SDL_thread.h>
```
但是实际路径`/usr/include/SDL/SDL.h`

在项目属性里加上了这个目录,
虽然IDE显示头文件找到了
但解析符号还是各种找不到...

这个功能叫`Indexer`
通过菜单操作`Project->C/C++ Index -> Rebuild`,就OK了.

### 改Eclipse主题
Eclipse menu -> Help -> Eclipse Marketplace, search "Eclipse Color Theme Plugin"