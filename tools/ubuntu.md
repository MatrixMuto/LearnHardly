#About Ubuntu
*记录Ubuntu系统配置的一些*

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

###终于找到关闭全半角切换(shift+space)快捷键的地方了
在Fcitx设置的,|Global Config|那页,勾上|Show Advance Option|,就可以找到了.


###uefi..
[StackOverflow](http://askubuntu.com/questions/369284/install-grub2-on-uefi-gpt-create-boot-partition-and-transfer-clonezilla-image)

[Managing EFI Boot Loaders for Linux](http://www.rodsbooks.com/efi-bootloaders/)

###给Android Studio添加Launcher Shortcut.
* Ubuntu有两个目录,里面存着很多程序的快捷方式.
  * `/usr/share/Applications/`
  * `~/.local/share/applications`
* 但是Android Studio的程序的Title改不掉..

### 给Ubuntu换个Theme..
* 参考[链接](http://sourcedigit.com/9432-top-10-best-custom-themes-ubuntu-14-04/)
* 有名的就是`Numix`了..
* 步骤
  1. 安装一些工具
  ```
  sudo apt-get install unity-tweak-tool gnome-tweak-tool
  ```
  2. 安装想要的主题
  ```
  sudo add-apt-repository ppa:numix/ppa 
  sudo apt-get update 
  sudo apt-get install numix-gtk-theme numix-icon-theme-circle 
  sudo apt-get install numix-wallpaper-notd
  ```
  3. 再用DASH打开`unity tweak tool`,在里面选上想要的Theme就好了.
* 升级到`16.04`的话,需要重新再安装一下.
  ```
  sudo apt-get install numix-gtk-theme
  ```

## 启动自动加载swap分区
- `blkid`看分区状态
- 修改`/etc/fstab`文件

## Bash->Profile里可以修改字体和大小, 这样vim就可以显示更多代码了...

## 用vim的make命令, 完了之后, 它会帮你跳到第一个waring/error的代码位置...
