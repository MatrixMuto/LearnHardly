*文件名不对,应该就是git*
#GitHub Manunal
> *我的GitHub手册*

###基础阅读内容

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
