###站在牛人的肩膀上
* [Tengine项目首页](http://tengine.taobao.org/index_cn.html)
* [Tengine团队写的书](http://tengine.taobao.org/book/index.html)
* [知乎上入门的回答](https://www.zhihu.com/question/20857459)
* [openresty/lua-nginx-module](https://github.com/openresty/lua-nginx-module)
* [源码注释交流平台](http://www.imaotao.cn/xref/nginx-1.10.0/)
* [深入理解Nginx](http://product.dangdang.com/23910258.html#catalog)
* [org网上推荐的书](http://nginx.org/en/books.html)
* [Mastring Nginx](http://product.dangdang.com/23655331.html#catalog) [PDF_LINk](http://pdf.th7.cn/down/files/1411/Mastering%20Nginx.pdf)
* [Nginx High Perfomance](http://product.dangdang.com/1900482176.html#catalog) [PDF_LINK](http://185.49.84.138/ebooks/Nginx-High-Performance[ebooksfeed.com].pdf)

###core/nginx.c
* main
```
return ngx_signal_process(cycle, ngx_signal);
```

###core/ngx_cycle.c
* ngx_signal_process
```
return ngx_os_signal_process(cycle, sig, pid);
```


###os/unix/ngx_process.c
* ngx_os_signal_process
```
    for (sig = signals; sig->signo != 0; sig++) {
        
    }
```

>以上流程是用于向已经在运行的nginx进程发信号的.
比如执行时
```
#/usr/local/nginx/sbin/nginx -s stop
```
这个新进程就会走上面的流程.

###os/unix/ngx_process_cycle.c
* ngx_single_process_cycle
```
ngx_process_events_and_timers(cycle);
```

###event/ngx_event.c
ngx_process_events_and_timers
```

```



#Read nginx-rtmp source code

[here is xref]()
#带着问题去看代码？
1.找到读取配置文件的模块。
2.ngx_process 有 single,master,signaller,worker,helper

#浏览代码

## main
    
    
* ngx_get_options
* ngx_init_cycle
* ngx_single_process_cycle
    ngx_process_events_and_timers
    


##重要的结构
core/nginx.c:158
``` c
ngx_module_t ngx_core_module = {
    
}
```

