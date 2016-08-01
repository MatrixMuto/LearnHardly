
###PS2：使用“sh -x script_name.sh”可以调试Shell脚本。

###'|| exit 1'这个是什么语法
```
AND and OR lists are sequences of one or more pipelines separated by the control operators ‘&&’ and ‘||’, respectively. AND and OR lists are executed with left associativity.

An AND list has the form

command1 && command2
command2 is executed if, and only if, command1 returns an exit status of zero.

An OR list has the form

command1 || command2
command2 is executed if, and only if, command1 returns a non-zero exit status.
```
[Bash Manual](https://www.gnu.org/software/bash/manual/bashref.html)

###部署Nginx&Rtmp的脚本
```shell
#Download nginx source code
#Download nginx-rtmp source code

#Configure & Complile

#install

#Config file nginx

```

###File attributes compa
[Link](https://bash.cyberciti.biz/guide/File_attributes_comparisons)
[unix-linux-test-existence](http://www.cyberciti.biz/faq/unix-linux-test-existence-of-file-in-bash/)

```shell
test -e filename
[ -e filename ]
 
test -f filename
[ -f filename ]

[ -f /etc/hosts ] && echo "Found" || echo "Not found"

#!/bin/bash
file="/etc/hosts"
if [ -f "$file" ]
then
	echo "$file found."
else
	echo "$file not found."
fi

```

