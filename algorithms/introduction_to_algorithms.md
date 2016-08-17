#Reading Introduction to Algorithms
这本书简称(CLRS),作者的姓.
[电子书地址](http://folk.ntnu.no/nicolaat/uni/Algdat/%5BThomas_H._Cormen,_Charles_E._Leiserson,_Ronald_L.(BookFi.org).pdf)
[GitHub的参考答案](https://github.com/gzc/CLRS)

##1. The Role of Algorithms in Computing

###1.1 Algotithms
* Hard Problems
  * NP完全问题
    * 没人知道是不是有解决方法
    * 如果一个解决了,其他都解决了
    * 有几个问题相似
* Parallelism(并行)

###1.2 Algorithms as a technology

##2. Getting Started
###2.1 Insertion sort
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
