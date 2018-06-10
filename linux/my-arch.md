VMWare慢慢体验ArchLinux的折腾
0. 创建一个Linux虚拟机
1. 下载镜像
[下载页面](https://www.archlinux.org/download/)
[163镜像地址](http://mirrors.163.com/archlinux/iso/2018.05.01/)
2. 光驱启动，进到一个Shell，然后应该就可以开始自定义安装旅程了。。

[Guide不能少](https://wiki.archlinux.org/index.php/Installation_guide)
0. 第一步应该是分区了，我们折腾UEFI了，（这里虚拟机设置里要选上用EFI启动）
分区总是让人纠结的事情，不浮躁，慢慢读分区指导
 - 分区for root
 - 分区for EFI
[Arch分区指导](https://wiki.archlinux.org/index.php/Partitioning)

- LVM
- GPT
- EFI
- parted


0. 分区
 - 分一个fat32的efi分区，500MB+，需要打开esp，boot，标志位
 - 分一个boot分区，ext4的，500MB+
 - 剩下的分成linux的分区就好，用来做lvm的物理卷。
 
1. 创建LVM
 - 把/dev/sda3的lvm标志位打开即可
2. 格式化文件系统
 - mkfs.fat32
 - mkfs.ext4
 - lvm的创建略复杂，pvcreate，vgcreate，lvcretae等命令用用

3. mount文件系统

### 安装arclinux，安装bootloader（grub）

- grub
  教程又提到需要insmod lvm，但是其他电脑上的配置没有，可能是不需要的。
  
  
  grub-install 
  
  
  在更改配置后需要重新生成cfg文件
  grub
  
  
### 配置locale
  
### 配置网络等

!!!由于用到了lvm，initramfs需要重做
!!!先按照LVM那的修改配置文件，再重做
否则会遇到/dev/mapper/vg1-lovl1找不到，切记

### 必装的package
```
pacman -S lvm2 dhcpcd openssh zsh python docker lldb tmux tree curl wget
```
- lvm2
- dhcpcd

```
systemctl enable dhcpcd@interface.service
```

- openssh
- sshd配置，
	- 公私钥配置
- zsh
  修改默认zsh是chsh -l full path
- python
- 账户创建，权限管理等
- 文件系统mount
### MyArch是否要配置桌面环境
 - 毕竟IDE（Clion，Studio）都需要用桌面，
 - 如果只作为服务器就用不到了


