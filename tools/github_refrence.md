*文件名不对,应该就是git*
#GitHub Manunal
> *我的GitHub手册*

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
* 