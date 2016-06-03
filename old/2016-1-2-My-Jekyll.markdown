---
layout: post
title:  "My Jekyll重复手册"
date:   2015-1-2 18:02:32 +0000
categories: jekyll update
---
第一个要看的肯定是[Jekyll docs][jekyll-docs]

服务器：
Raspberry Pi
Debian + Jekyll + Samba
把Jekyll的目录直接共享出来

以前公司里有台Ubuntu想要共享，却一直都找不到准确的文档，这次找到了，长知识！
[Samba Config][samba-cfg]

编辑环境：
Windows上 Sublime Text 3 直接编辑共享目录的文档

为Markdown还要好好配置Sublime Text，当是使用Sublime Text的开始。

据说最好的Markdown Editor是[Mou][Mou]

http://blog.saymagic.cn/2015/01/01/sublime_text_concise_course.html

http://blog.saymagic.cn/2015/06/20/write-blog-by-sublime.html

这个Blog还有关于Jekyll的一些经验分享，可以学习。

Sublime Text 中文输入法框跟不上光标的解决方案，[Link][IMESupport]

Sumlime Text 的配置，由于GFW的问题，想来也是麻烦，需要寻找简单的替代办法。


预览：
Chorme访问服务器

提交：
Putty上去用Git Push

最终可以访问
[我的主页][main-page]


[jekyll-docs]: http://jekyllrb.com/docs/home
[main-page]: http://matrixmuto.github.io
[samba-cfg]: https://www.howtoforge.com/tutorial/debian-samba-server
[Mou]: http://25.io/mou
[IMESupport]: https://yian.me/blog/cs/sublime-text-3-imesupport.html