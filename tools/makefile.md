###Book
[Managing Projects with GNU Make, 3rd Edition
The Power of GNU make for Building Anything]()

###Makefile
* 定义变量
  VAR = var
* 取变量值
  $(VAR) 
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
[doc](http://www.math.utah.edu/docs/info/make_4.html#SEC27)

The vpath Directive

Similar to the VPATH variable but more selective is the vpath directive (note lower case), which allows you to specify a search path for a particular class of file names, those that match a particular pattern. Thus you can supply certain search directories for one class of file names and other directories (or none) for other file names.

There are three forms of the vpath directive:

vpath pattern directories
Specify the search path directories for file names that match pattern. The search path, directories, is a list of directories to be searched, separated by colons or blanks, just like the search path used in the VPATH variable.
vpath pattern
Clear out the search path associated with pattern.
vpath
Clear all search paths previously specified with vpath directives.
A vpath pattern is a string containing a `%' character. The string must match the file name of a dependency that is being searched for, the `%' character matching any sequence of zero or more characters (as in pattern rules; see section Defining and Redefining Pattern Rules). For example, %.h matches files that end in .h. (If there is no `%', the pattern must match the dependency exactly, which is not useful very often.)

`%' characters in a vpath directive's pattern can be quoted with preceding backslashes (`\'). Backslashes that would otherwise quote `%' characters can be quoted with more backslashes. Backslashes that quote `%' characters or other backslashes are removed from the pattern before it is compared to file names. Backslashes that are not in danger of quoting `%' characters go unmolested.

When a dependency fails to exist in the current directory, if the pattern in a vpath directive matches the name of the dependency file, then the directories in that directive are searched just like (and before) the directories in the VPATH variable.

For example,

vpath %.h ../headers
tells make to look for any dependency whose name ends in `.h' in the directory `../headers' if the file is not found in the current directory.

If several vpath patterns match the dependency file's name, then make processes each matching vpath directive one by one, searching all the directories mentioned in each directive. make handles multiple vpath directives in the order in which they appear in the makefile; multiple directives with the same pattern are independent of each other.

Thus,

vpath %.c foo
vpath %   blish
vpath %.c bar
will look for a file ending in `.c' in `foo', then `blish', then `bar', while

vpath %.c foo:bar
vpath %   blish
will look for a file ending in `.c' in `foo', then `bar', then `blish'.

###eval

###include,-include
```
If you want make to simply ignore a makefile which does not exist or cannot be remade, with no error message, use the -include directive instead of include, like this:

-include filenames…
This acts like include in every way except that there is no error (not even a warning) if any of the filenames (or any prerequisites of any of the filenames) do not exist or cannot be remade.

For compatibility with some other make implementations, sinclude is another name for -include.
```

### GNU Make有很多隐式的规则和变量
[Using Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html)
* 隐式变量:
  * `CC`: default cc
* 后缀规则:
