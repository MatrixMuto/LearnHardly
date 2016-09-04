# Raspberry Pi

## RPi的架构
[PPT](http://www.macs.hw.ac.uk/~hwloidl/Courses/F28HS/slides_RPi_arch.pdf)

## 启动流程
1. 电源开启，GPU开始执行ROM内的first-satge代码，这段ROM代码，读取SDCard的second-stage bootloader到CPU的L2 Cache
2. 接着CPU启动，执行L2的代码，这段指令打开SDRAM，读第三阶段启动代码到内存，执行之
3. 第三阶段启动代码，读取GPU firmware(start.elf)

### 给树莓派装系统
[Link](https://www.raspberrypi.org/documentation/installation/installing-images/linux.md)
基本就几步
* 下载镜像
* umount
  ```
  umount /dev/sd*x*1
  ```
* 写卡
  ```
   sudo dd bs=4M if=2016-05-27-raspbian-jessie.img of=/dev/sd*x*
  ```
* sync一下