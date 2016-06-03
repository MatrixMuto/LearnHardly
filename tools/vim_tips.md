


##Vim Tab



##Plugins
###ctags


###cscope
* cs find
```
:cs find e <reg>
```
> NOTE:字符分号也算是被搜索的内容的,注意

##Searching
  [wiki](http://vim.wikia.com/wiki/Searching)
  * Search word under cursor
  * '*'/'#' prev/next exact word

##Undo and Redo
  [Wiki](http://vim.wikia.com/wiki/Undo_and_Redo)
  * 'u' 'U' 'Ctrl+R'

##FAQ
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
  
* 公司/家里/其他电脑上,同步vim的配置
  通过GitHub来自定义吧.