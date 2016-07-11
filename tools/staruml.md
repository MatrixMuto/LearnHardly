
###设定默认的颜色,线的格式
在File->Prefrence里,General里设置

###我的StarUML设置

###真的不支持Java的Generics??
确实不支持Java的Generics...

###
在Model图里新建了一个Package,Model里就自动为你创建那个Model了,
你在View视图里的拖动都会同步改变Model的,所以要小心.

###UML2示例
[Link](http://creately.com/blog/diagrams/class-diagram-relationships/)

###Aggregation vs Composition
Simple rules:


A "owns" B = Composition : B has no meaning or purpose in the system without A
A "uses" B = Aggregation : B exists independently (conceptually) from A
Example 1:


A Company is an aggregation of People. A Company is a composition of Accounts. When a Company ceases to do business its Accounts cease to exist but its People continue to exist.


Example 2: (very simplified)


A Text Editor owns a Buffer (composition). A Text Editor uses a File (aggregation). When the Text Editor is closed, the Buffer is destroyed but the File itself is not destroyed.

----------------------------
Aggregation implies a relationship where the child can exist independently of the parent. Example: Class (parent) and Student (child). Delete the Class and the Students still exist.


Composition implies a relationship where the child cannot exist independent of the parent. Example: House (parent) and Room (child). Rooms don't exist separate to a House.


The above two are forms of containment (hence the parent-child relationships).


Dependency is a weaker form of relationship and in code terms indicates that a class uses another by parameter or return type.


Dependency is a form of association.

#UML
###Associtaion, Directed Associtation 和 Aggregation, Composition有什么区别?