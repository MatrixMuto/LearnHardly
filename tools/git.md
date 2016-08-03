*文件名不对,应该就是git*
#GitHub Manunal
> *我的GitHub手册*

###基础阅读内容
> Book is [here](https://git-scm.com/book/en/v2)
## 常用链接
* [GitHub Help](https://help.github.com/)

##With Android Studio

##With VS Code

##With Terminal

##Proxy
```
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'
```

###git clone --reference 

###git repack -a ?

###git fetch --all --tags ?

###git --verison

###git checkout <commit> -B ijkplayer??

###当你本地分支有改动(local changes)时,你pull remote时,如果冲突的话,会提示让你commit或者stash.

###git checkout 分支的时候,local change会被保留

###git clone完,如何切换远程分支??

###how to fix git commit wrong branch
[answer](http://stackoverflow.com/a/2941598)
```
git reset --soft HEAD^
```

###怎么看某个commit的详细内容?
* 先怎么看更改了哪些文件?
```shell
git log -p -1
```
* 看那个文件的具体diff,怎么用我熟悉的工具(BeyondCompare)

#Read Pro Git
> Book is [here](https://git-scm.com/book/en/v2)

###Git的Submodule能发挥什么作用?
* 好像是制定了某个仓库的某个版本(分支+commit)
* 使用手册呢?


###What are the differences between SVN and Git?
[What are the differences between SVN and Git?](https://help.github.com/articles/what-are-the-differences-between-svn-and-git/)

###什么是branch的track?
```
git branch --set-upstream-to stapler remotes/origin/stapler
```
设置了这个以后,git pull, git push 的行为好像就变了..

###怎么关注一个仓库每个分支的提交?有推送吗?是不是GitHub提供的Watch功能?

###怎么查当前版本下,某文件的某行代码是什么时候添加的?

###远程仓库新建了分支(July),本地仓库如何新建,跟踪,切换到这个分支?
如果有Local Change, 不产生冲突的话, 会自动合并.    
```
$ git checkout -b serverfix origin/serverfix
Branch serverfix set up to track remote branch serverfix from origin.
Switched to a new branch 'serverfix'
```

###git stash怎么用...?

###github上怎么删除一个branch
仓库首页,有个[branches页面](https://github.com/MatrixMuto/LearnHardly/branches),可以点一下鼠标就删除了.
命令行怎么删除远程仓库的分支呢?


###git的分支merge?
```
git config branch.july.merge refs/heads/july
```


##git remote show origin
```
$ git remote show origin 
* remote origin
  Fetch URL: https://github.com/MatrixMuto/MyTestBeds.git
  Push  URL: https://github.com/MatrixMuto/MyTestBeds.git
  HEAD branch: master
  Remote branches:
    master  tracked
    stapler tracked
  Local branch configured for 'git pull':
    master merges with remote master
  Local ref configured for 'git push':
    master pushes to master (up to date)
```


###Git怎么在新的分支上工作
用上次的Git创建的Branch上,进行push,结果遇到错误,
```
error: failed to push some refs to 'https://github.com/MatrixMuto/LearnHardly.git'
hint: Updates were rejected because a pushed branch tip is behind its remote
hint: counterpart. If you did not intend to push that branch, you may want to
hint: specify branches to push or set the 'push.default' configuration variable
hint: to 'simple', 'current' or 'upstream' to push only the current branch.
```
不明就里的设置了current,
结果在远程仓库那就创建了个分支..

问题是, 'simple', 'current', 'upstream' 有什么区别?

```
warning: push.default is unset; its implicit value is changing in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the current behavior after the default changes, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

When push.default is set to 'matching', git will push local branches
to the remote branches that already exist with the same name.

In Git 2.0, Git will default to the more conservative 'simple'
behavior, which only pushes the current branch to the corresponding
remote branch that 'git pull' uses to update the current branch.

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)
```

###怎么在仓库里,建立一个别的仓库的submodule?
```
git submodule add ./ffmpeg
```
好像有效果,应该要是个url地址

###git reset --hard HEAD

###怎么把已经跟踪的文件,从仓库删除,但是本地依然存在?
```
git rm --cached <path/to/file>
```

###删除创建的SubModule
```
git submodule uninit <dir> 
```
这个命令不太对,可能要试试
```
git rm -rf <dir>
```

###在Windows上使用Git时，Git处理文件的换行符时，可能会采用CRLF的方式。
* 这样会产生什么问题?
  * 提交的时候Git会再把CRLF转换回LR吗?
* 有什么好的方式处理这些问题?

###清理工作目录的命令
```shell
git clean -f -d -x
```