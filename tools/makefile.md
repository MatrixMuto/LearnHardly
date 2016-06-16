###Makefile
* 定义变量
* 取变量值
* 取环境变量


###Basic of Var Ref

Basics of Variable References


To substitute a variable's value, write a dollar sign followed by the name of the variable in parentheses or braces: either `$(foo)' or `${foo}' is a valid reference to the variable foo. This special significance of `$' is why you must write `$$' to have the effect of a single dollar sign in a file name or command.

Variable references can be used in any context: targets, prerequisites, commands, most directives, and new variable values. Here is an example of a common case, where a variable holds the names of all the object files in a program:
```
objects = program.o foo.o utils.o
program : $(objects)
        cc -o program $(objects)

$(objects) : defs.h
```
Variable references work by strict textual substitution. Thus, the rule
```
foo = c
prog.o : prog.$(foo)
	$(foo)$(foo) -$(foo) prog.$(foo)
```



###
指定编译工具和编译命令的事情应该是在configure脚本里制定的
脚本是通过直接修改Makefile还是Makefile引用的其他子makefile呢?
ffmpeg的Makefile的第二行指定了
```
include config.mak
```