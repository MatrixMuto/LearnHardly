#About Ubuntu

>又重装系统了,装了个Ubuntu 16.04,[download](),过程曲折,结局悲催.

>Linux就是折腾,但目前不能花太多时间啊



##该如何配置我的N56VZ的系统
* 我会需要Windows,使用一些软件(游戏,照片处理,视频编辑,一些只有Windows版本的软件)
* 

##有哪些选择?
* 目前是SSD安装Windows,HD装各种Linux.
* SSD里安装Ubuntu＋Windows,HD里放文档.

##How to setup disk partion for filesystem/mount point.
* mutli 
##SSD里安装Ubuntu
* 会对SSD寿命有影响吗?毕竟Windows



##How to fix my nvidia video card issue?
* Use intel video card for two monitor.
* Disable GT650M...
* I installed bump via
```
sudo apt-get install bumblebee bumblebee-nvidia primus linux-headers-generic
```
but i got 
```
muto@muto-nvz:~$ optirun nvidia-settings
[ 2603.067711] [ERROR]Cannot access secondary GPU - error: Could not load GPU driver

[ 2603.067792] [ERROR]Aborting because fallback start is disabled.

```

* How to know if my nv is on?


##Nessangy Softwares
* GParted
* Sogou Pinyin
> [Download and Guide]()
* Chrome
* Beyond Compare
* Shadowsocks
> json,finalspeed,switchproxy
* Git
> config
* VS Code
> plugin,config
* StarUML
* Android Studio
> config via github
* android-sdk
* android-ndk
* android-master
* open-jdk
* oracle-jdk
* Wireshark
* ffmpeg
* avplay
* vlc

# How to install and config up software
* I need learn a script language such as shell,python
* via command

``` shell
sudo apt-get install gparted git-core
```
* via download && install

``` 

```

#What files need to be backup.
* Config Files
> Ubuntu Configs
* Project Files
> via GitHub?


##Many linux display managers
> [xxx](http://www.makeuseof.com/tag/choose-switch-linux-display-managers/)
* LightDM


###LightDM
[wiki](https://wiki.ubuntu.com/LightDM)
``` 
sudo dpkg-reconfigure ligh
```


#How to enable or disable services?
[answer of askubuntu](http://askubuntu.com/questions/19320/how-to-enable-or-disable-services)

##Installation FromLinux
[Installation FromLinux](https://help.ubuntu.com/community/Installation/FromLinux)
  硬盘分区的概念
  GPT,MBR,
  启动系统 Grub2
* rsync?


http://everythinglinux.org/rsync/
