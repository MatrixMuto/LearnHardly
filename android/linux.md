
##内核同步

###自旋锁(spin lock)
* 自旋锁不会让线程阻塞,它会轮询.
    ```c
    spin_lock
    spin_unlock
    ```