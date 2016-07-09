
###内部类
静态内部类
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
每个inside_class的实例都会有一个outside的指针??

###为什么在|extends HandlerThread|的时候,我必须实现一个构造函数?
>在grafika的例子里,是通过继承|Thread|+|Looper|来实现的.

###你在设计的时候,才会考虑怎么样比较好,写完之后你才懒的改?

###复用
* 7.2 继承语法(Inheritance syntax)
  * 继承会得到基类的所有field和method.
  * 任何类不是继承于其他类就是继承于Obejct
* 7.6 protected
  * 就类用户而言,这时privtae的,但对于**此类的导出类**或**其他任何一个位于同一个包内的类**来说,它是可以访问的.
  * 
* 7.7 向上转型(Upcasting)
  * 向上转型是安全的,会丢失方法.
  * 向上转型,是指导出类的引用转换为基类引用的动作.
  * ?编译器怎么实现的?
* 7.8 final
  * final可以用在三个地方,数据,方法,类
  * final数据
    * 一个永不改变的编译常量 
    * 一个在运行时初始化的值，但不希望它被改变 对于对象引用
    * 对于基本类型,使数值很定不变,对于对象引用,final使引用恒定不变,一旦指向一个对象之后,就没有办法指向另外一个对象.
    * 但是对象自身是可以修改的.
    * 适用于数组,数组也是对象.
    * **blank final**,允许运行时再初始化.
  * final参数
    * 无法在方法中修改参数引用所指向的对象.
    * ?那调用对象的方法,那个方法里修改了对象,算不算?
  * final方法
    * 1.设计目的,在导出类中,保持这个方法的行为不被改变,且不被覆盖.
    * 本来还有一个效率目的,但是现在这件事情由虚拟机自动做掉了.
    * 所以,
    > make a method final only if you want to explicitly prevent overriding.
    * final and private
      * Any private methods in a class are implicitly 
      * override?
  * final类
    * 出于设计或安全,final类不能被继承
    * final类的域可以是final也可以不是finla
    * final类的方法,都是隐式final的
###多态(Polymorphism)
  
  * 0.引言
    * 消除类型之间的耦合关系
    * 继承使得对象可以被当做其类型或其基类型来处理,从而使得多种类型可以被当做一种类型来处理,同一份代码可以运行在不同类型之上.
    * 可以通过同一个基类的方法调用,表现出不同的行为.
  * 1.再谈向上转型
    * 对某个对象的引用视为对其基类型的引用的做法,被称作向上转型.
    
  * 构造器与多态
    * 构造器函数都是隐式static.
    * 基类的构造器总是在导出类的构造器中被调用,而且按照继承层次逐渐向上链接,以使每个基类的构造器都能的到调用.
    * 保证对象被正确地构造. 又因为基本的成员一般是private的, 只有基类的构造函数能正确去初始化.
    * 所以编译器强制导出类必须调用基类构造器函数.
    * 如果导出类的构造器没有调基类的某个构造器,就会默默调用默认的构造器函数
      此时,如果基类没有默认的构造器喊出,编译器就会报错.
