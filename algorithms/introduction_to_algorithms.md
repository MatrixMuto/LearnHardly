#Reading Introduction to Algorithms
这本书简称(CLRS),作者的姓.
[电子书地址](http://folk.ntnu.no/nicolaat/uni/Algdat/%5BThomas_H._Cormen,_Charles_E._Leiserson,_Ronald_L.(BookFi.org).pdf)
[GitHub的参考答案](https://github.com/gzc/CLRS)

## 1. The Role of Algorithms in Computing

### 1.1 Algotithms
* Hard Problems
  * NP完全问题
    * 没人知道是不是有解决方法
    * 如果一个解决了,其他都解决了
    * 有几个问题相似
* Parallelism(并行)

### 1.2 Algorithms as a technology

## 2. Getting Started
### 2.1 Insertion sort
* 把一个待排序的元素, 插入到已排序的序列中.
```C
void insertion-sort(void *A)
{
    int i,j,k;
    for (j = 2; j < n; ++j){
        k = A[j];
        i = j-1;
        while(i > 0 && A[i] > k)
        {
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = k;
    }
}
```
* 循环常量(Loop invariant)


## 看公开课视频(6.046J) 网易版
* 前置课程: 计算机数学基础, 离散数学, 概率论
* 算法导论第一课
  * 均匀分布, 概率论, 平均复杂度(需要假设输入的分布)
  * 渐进分析, 考虑算法的增长, 
    忽略低阶,忽略常量,用[mathjax](\theta)表示
  * 算术级别
  * 线性时间, Linear time.
  * 递归树 技术 T(n) = 2T(n/2) + cn
  * 课后作业

## 看公开课(6.006)视频, 课后习题
* 渐进分析
* 递归算法的复杂度分析
* Peek finding(一维)的证明, 峰肯定存在. 根据这一性质, 再设计2分的算法.
* Peek finding(二维) ???