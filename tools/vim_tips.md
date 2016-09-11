


## Vim Tab



## Plugins
### ctags


### cscope
* cs find
```
:cs find e <reg>
```
> NOTE:字符分号也算是被搜索的内容的,注意

## Searching
  [wiki](http://vim.wikia.com/wiki/Searching)
  * Search word under cursor
  * '*'/'#' prev/next exact word

## Undo and Redo
  [Wiki](http://vim.wikia.com/wiki/Undo_and_Redo)
  * 'u' 'U' 'Ctrl+R'

## FAQ
* 高亮代码?


* 显示当前文件名/路径?
```
set title
or
set ls=2
or
set statusline=2
``` 
ref:
1. [Link](http://stackoverflow.com/questions/10488717/how-can-i-permanently-display-the-path-of-the-current-file-in-vim)
2. help statusline

* 移动Cursor到上/下个函数?


* TAB变成插入4个空格?

* 小写大写
  gu gU

* 删除光标所在的Word
 ved vbd de

* goto line 42
  ```
  42G
  42gg
  :42<CR>
  ```

### 同步配置我的Vim
* 公司/家里/其他电脑上,同步vim的配置,通过GitHub来自定义吧.
* 完全没有配置的时候,从GitHub上克隆一个,安装.
  ```shell
  git clone https://github.com/MatrixMuto/vim_config.git
  sh vim_config/install.sh
  ```
* 之后就一可以通过Git命令进行同步了.
* 基本都是照[这个amix/vimrc](https://github.com/amix/vimrc/)开源项目配置的.
* 项目中管理插件的理解
  1. 首先,会在`.vimrc`配置文件中加上一行`set runtimepath+=~/.vim_runtime`,使得vim会自动加载这个目录下的插件.
  2. `~/.vim_runtime`下面,一定有一个`autoload`目录,这是vim的解析规则.
  3. 用`pathogen`插件来管理其他插件.
  4. `.vimrc`文件里可以通过`source xxx.vim`来包含其他部分的内容,这属于`vim`配置的语法.

### Vim怎么执行shell命令?
* 可以`Ctrl+Z`切到Shell中敲.
- `:!<cmd>`
### VIMRUNTIME是什么??

### `~/.vim`目录干嘛的?

### vim有几个插件管理工具.
* [egalpin/apt-vim](https://github.com/egalpin/apt-vim)
* [tpope/vim-pathogen](https://github.com/tpope/vim-pathogen)

### 重新加载`.vimrc`配置
If you're editing it, you can reload it with:
```
:so %
```
% stands for current file name (see :h current-file) and :so is short for :source, which reads the content of the specified file and treats it as Vim code.

In general, to re-load the currently active .vimrc, use the following (see Daily Vim):

```
:so $MYVIMRC
```

### vim stuck
在`Insert`模式，按过`Ctrl+s`，会僵掉，按`ctrl+q`可以解。
这俩键可看[Software flow control](https://en.wikipedia.org/wiki/Software_flow_control)

### vim recording
- 在Normal模式按q可以取消。

## 插件*YouCompleteMe*
[网站](https://valloric.github.io/YouCompleteMe/)
需要有一个install过程

