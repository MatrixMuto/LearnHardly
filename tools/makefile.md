###Book
[Managing Projects with GNU Make, 3rd Edition
The Power of GNU make for Building Anything]()

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



###Makefile include
指定编译工具和编译命令的事情应该是在configure脚本里制定的
脚本是通过直接修改Makefile还是Makefile引用的其他子makefile呢?
ffmpeg的Makefile的第二行指定了
```
include config.mak
```

###Makefile 还能定义函数啊...
```
define DOSUBDIR
$(foreach V,$(SUBDIR_VARS),$(eval $(call RESET,$(V))))
SUBDIR := $(1)/
include $(SRC_PATH)/$(1)/Makefile
-include $(SRC_PATH)/$(1)/$(ARCH)/Makefile
-include $(SRC_PATH)/$(1)/$(INTRINSICS)/Makefile
include $(SRC_PATH)/library.mak
endef

$(foreach D,$(FFLIBS),$(eval $(call DOSUBDIR,lib$(D))))
```

###赋值
* **:=**,**=**这两个有什么区别呢?
* **+=**

###foreach

###wildcard

###vpath

###eval

###include,-include
