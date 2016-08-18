## 资源
- [Thinking in Java](http://sd.blackball.lv/library/Thinking_in_Java_4th_edition.pdf)

---
# FAQ

### 为什么在|extends HandlerThread|的时候,我必须实现一个构造函数?
>在grafika的例子里,是通过继承|Thread|+|Looper|来实现的.

### 你在设计的时候,才会考虑怎么样比较好,写完之后你才懒的改?

### 弱引用(WeakReference)

## AtomicInteger

### Overload vs Override
* Override：有人翻译是重写，有人翻译是覆写，覆盖等。
  其实更像是一种扩展，因为它是在父类中声明方法（一般是抽象的），在子类中根据需求去具体定义方法的行为（即modify behavior as needed）
  它要求override的方法有相同的名字、相同的参数、相同的返回值类型（即the same name, number and type of parameters, and return type）。它是一种晚绑定，是决定java多态的一种方式。
* Overload: 重载, 同一个类,同一个名字, 通过方法签名来区分, 编译时决定.
* [参考一](https://users.soe.ucsc.edu/~charlie/book/notes/chap7/sld012.htm)
  [参考二](http://www.programcreek.com/2009/02/overriding-and-overloading-in-java-with-examples/)

# Thinking in Java

### 复用
* 7.2 继承语法(Inheritance syntax)
  * 继承会得到基类的所有field和method.
  * 任何类不是继承于其他类就是继承于Obejct
* 7.6 protected
  * 就类用户而言,这是privtae的,但对于**此类的导出类**或**其他任何一个位于同一个包内的类**来说,它是可以访问的.
  * 
* 7.7 向上转型(Upcasting)
  * 向上转型是安全的,会丢失方法.
  * 向上转型,是指导出类的引用转换为基类引用的动作.
  * ?编译器怎么实现的?
* 7.8 final
  * final可以用在三个地方,数据,方法,类
  * final数据
    * 一个永不改变的编译常量 
    * 一个在运行时初始化的值， 但不希望它被改变, 对于对象引用
    * 对于基本类型, 使数值很定不变
    * 对于对象引用, final使引用恒定不变
    * 一旦指向一个对象之后, 就没有办法指向另外一个对象, 但是对象自身是可以修改的.
    * 适用于数组, 数组也是对象
    * **blank final**,允许运行时再初始化
  * final参数
    * 无法在方法中修改参数引用所指向的对象
    * ?那调用对象的方法,那个方法里修改了对象,算不算?
  * final方法
    * 设计目的,在导出类中,保持这个方法的行为不被改变,且不被覆盖
    * 本来还有一个效率目的,但是现在这件事情由虚拟机自动做掉了
    * 所以,只有想你想要阻止一个方法被重写时,才把它加上final
    * final and private
      * Any private methods in a class are implicitly 
      * override和overload怎么理解它们的区别?
  * final类
    * 出于设计或安全,final类不能被继承
    * final类的域可以是final也可以不是final
    * final类的方法,都是隐式final的

### 多态(Polymorphism)
  - 引言
    * 消除类型之间的耦合关系
    * 继承使得对象可以被当做其类型或其基类型来处理,从而使得多种类型可以被当做一种类型来处理,同一份代码可以运行在不同类型之上.
    * 可以通过同一个基类的方法调用,表现出不同的行为.
  - 再谈向上转型
    * 对某个*对象的引用*视为对其*基类型的引用*的做法,被称作向上转型.
  - 转机?
    * 编译器无法知道*基类型的引用*, 到底是哪个导出类的类型. 这是运行时绑定的职责.
    * 方法调用绑定
      * 动态绑定. 
      * 使代码有更好的扩展性. 以基类型引用作为参数的方法不需要更改,就处理新的继承类型.
      * 陷阱:类的private方法自动是final,不会被overload.
      * 陷阱:字段和静态方法, 字段是在编译时确定的, 静态方法是和类绑定的,而非对象. 这俩个不具有多态性.
  - 构造器与多态
    * 构造器函数都是隐式static.
    * 基类的构造器总是在导出类的构造器中被调用,而且按照继承层次逐渐向上链接,以使每个基类的构造器都能的到调用.
    * 保证对象被正确地构造. 又因为基本的成员一般是private的, 只有基类的构造函数能正确去初始化.
    * 所以编译器强制导出类必须调用基类构造器函数.
    * 如果导出类的构造器没有调基类的某个构造器,就会默默调用默认的构造器函数. 此时,如果基类没有默认的构造器喊出,编译器就会报错.
  - 向下转型和运行时类型识别(RTTI)
    * 运行时,向下转型会进行检查, 不正确的话会抛出*ClassCastException*.

### 内部类
* 静态内部类和内部类的区别?
  * 内部类的对象在创建时,必须通过其外部类的对象.
* 静态内部类
  ```java
  class outside {
    static int static_variable;
    int variable;
    static class static_indise_class {
    }

    class inside_class{
    }

    }
  ```
  每个inside_class的实例都会有一个outside的引用??
* 一般情况下,外部类会有一个函数返回内部类对象的引用.
* 除了在外部类的非静态方法里,其他地方,你想要创建一个内部类的对象,你必须以OuterClassName.InnerClassName的方式.
* 内部类会有一个外部类对象的引用.
* 除非你有一个外部类的对象,否则你不可能创建一个内部类的对象.
* 嵌套类,当然,你如果加了一个static就另当别论了.
* 内部类可以被overridden吗?
  可能并没有这个概念,内部都是有独立名称空间的类.
  可以在类中明确继承那个内部类.
* 局部内部类(Local inner class)

### Everything is Object
* Java是一个更纯粹的面向对象语言.
* 每种语言都有它自己的操作内存中元素的方法,Java的概念是引用.它跟C++的引用有一些重要的区别.
* 有5个存数据的地方,寄存器(Registers),栈(stack),堆(heap),常量(constant),非内存(Non-RAM)
* primitive and its wrapper class
* BigInteger and BigDecimal
* Java数组有边界检查,是引用的数组,初始值是null.
* 任何时候都不用destroy一个对象
* 大括号,作用域,生命周期.
* 和C/C++不用的一点,C/C++会隐藏名字一样的变量,Java会报编译错误.
  ```java
  { int x=12; {int x=12;//Illegal}}
  ```
* Java对象的生命周期和原型变量不同. 作用域外,对象的生命周期还在,只是无法访问了.?是在垃圾回收的时候才结束吗?
* 垃圾回收,避免一类问题,内存泄露.
* 类里有两类元素,field(data members), method(memmber functions)
* filed可以是原型变量或对象引用
* 原型变量会被Java初始化,只有当这个变量是成员变量的时候. 当它是局部变量的时候,如果你没有初始化,Java编译器会报错.
* 方法只能作为类的成员存在. 方法只能通过对象调用(静态方法通过类调用)

### Type Information
Runtime type Information(RTTI), 可以在程序运行时发现使用类型信息.
* 为什么需要RTTI?
  * 多态需要动态绑定,实现动态绑定的机制,就是RTTI.
* Class对象
  * Class object拥有class的信息
  * 每个类都有一个Class对象,编译时创建存储在*.class*文件中.
  * JVM用*class loader*来创建对象
  * 所有类都是在需要时才被load的,发生在类的静态成员(也包括构造函数)被引用的时候.
  * 动态加载使得Java做一些复杂的事情.
  ```java
  Class.forName()
  getClass()
  isInterface()
  Class.getInterfaces()
  getSuperclass()
  
  ```
  *
* 反射(Reflection)
 * jee
* 总结
 
# 设计模式(Design Patterns)

### Step Builder Pattern
Builder模式的一种扩张.
把复杂对象的构建,分成有次序的步奏,引导用户,直到恰到的时候才可以build.

### Builder
