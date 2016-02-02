需求是:
当前的TaskStack是：Activity A -> Activiy B-> Activity C
此时发生事件，startActivity A
能够达到TaskStarck= Activity A
理论上只需要加上 ** FLAG_ACTIVITY_CLEAR_TOP ** 就可以了。

同事JX，告诉我，他的Acivity可以使用action=xxx就可以启动了。
最终解决问题的关键点是 通过看A的manifest才发现了Activity D的存在。
原来TaskStack底部的A，其实是D
而通过action=xxx启动的才是我们认为的Activity A。

虽然A和D都是同一个Activity。
但是A是一个用activity-alias声明的Activity，
最后是通过删除了D的声明，使最后只有一个Activity A,来解决这个问题。

遗留问题：
1.作为Activity C,如果发现启动的D和A,其实是不一样的？

2.如何启动A，而不是D？

这中间，主要看了的文档是
[Intent](http://developer.android.com/intl/zh-cn/reference/android/content/Intent.html)
[** Task and back stack **](http://developer.android.com/guide/components/tasks-and-back-stack.html)

还需要深入了解。。