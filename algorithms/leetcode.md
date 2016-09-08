
#223 Rectangle Area
求两个线段的重叠长度.
扩展:[求N个线段的覆盖长度](http://www.nowcoder.com/questionTerminal/0b4f611b96a24c0980e42509b13b0f42?orderByHotValue=1&done=0&pos=248&mutiTagIds=597&onlyReference=false)

##372. Super Pow
计算a的b次方 mod 1337的值.
* 取模运算的一些运算公式
* 再利用分治的思想,或递归的思想.

##50. Pow(x,n)
实现这个公式.
* 把n按照二进制位的方式递归. 从最低位开始.
* 需要注意以下情况
  * n<0
  * x == 1 or x == -1
  * n = INT_MIN


##34. Search for a Range
https://leetcode.com/problems/search-for-a-range/
[TODO: 这个解法才是O(logn)](https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation)

##77. Combinations
>Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
递归的方法. 88ms
* 是不是用DP写会快??
* 非递归写法会快?

## ???99. Recover Binary Search Tree (Hard)
* 二叉查找树(Binary Search Tree)
  * 左子树的所有节点比根节点小,右子树的节点值比根节点大
  * 左右子树也是二叉查找树
* Wiki定义:
* 二叉查找树（英语：Binary Search Tree），也称二叉搜索树、有序二叉树（英语：ordered binary tree），排序二叉树（英语：sorted binary tree），是指一棵空树或者具有下列性质的二叉树：
  * 任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
  * 任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
  * 任意节点的左、右子树也分别为二叉查找树；
  * 没有键值相等的节点。
* 前序遍历这课树,

## ???[239. Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* 对所有长度为k的子序列, 遍历这个k个元素求最大值. O((n-k)k)
* 运用堆, 对所有长度为k的子序列,删除一元素, 插入一个新元素, 取最大值. O((n-k)lgk)
* 使用**Monotone priority queue**,
  >Wiki:a monotone priority queue is a variant of the priority queue abstract data type
  C++有个实现是`deque`,它只是双端队列.
  这道题的特点,需要删除队首元素,和删除队尾元素.
  还有点插入排序的思想,保证队列是从大到小的队列.
* 循环常量: deque中的元素都是从大到小排列的.
