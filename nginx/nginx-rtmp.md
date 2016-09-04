###nginx-rtmp是等到你发完C1,才回S0和S1.

###ngx_rtmp_amf_read

###ngx_rtmp_amf_get

###struct ngx_rtmp_amf_ctx_t

###怎么读nginx-rtmp的代码?

###是不是可以用GDB来调试Nginx呢?
* 设置成单master模式?
  
###常用结构体


```c
0038 struct ngx_cycle_s {
0039     void                  ****conf_ctx;
0040     ngx_pool_t               *pool;
0041 
0042     ngx_log_t                *log;
0043     ngx_log_t                 new_log;
0044 
0045     ngx_uint_t                log_use_stderr;  /* unsigned  log_use_stderr:1; */
0046 
0047     ngx_connection_t        **files;
0048     ngx_connection_t         *free_connections;
0049     ngx_uint_t                free_connection_n;
0050 
0051     ngx_module_t            **modules;
0052     ngx_uint_t                modules_n;
0053     ngx_uint_t                modules_used;    /* unsigned  modules_used:1; */
0054 
0055     ngx_queue_t               reusable_connections_queue;
0056 
0057     ngx_array_t               listening;
0058     ngx_array_t               paths;
0059     ngx_array_t               config_dump;
0060     ngx_list_t                open_files;
0061     ngx_list_t                shared_memory;
0062 
0063     ngx_uint_t                connection_n;
0064     ngx_uint_t                files_n;
0065 
0066     ngx_connection_t         *connections;
0067     ngx_event_t              *read_events;
0068     ngx_event_t              *write_events;
0069 
0070     ngx_cycle_t              *old_cycle;
0071 
0072     ngx_str_t                 conf_file;
0073     ngx_str_t                 conf_param;
0074     ngx_str_t                 conf_prefix;
0075     ngx_str_t                 prefix;
0076     ngx_str_t                 lock_file;
0077     ngx_str_t                 hostname;
0078 };
```
###nginx-rtmp-module的整体的框架是?
这个项目由多个nginx module组成.
这里需要先介绍一下nginx的模块化设计的东西:
* 每个模块肯定会定义**ngx_module_t**类型的全局结构体.
  * 例如*ngx_rtmp.c*中
    ```c
    ngx_module_t  ngx_rtmp_module = {
        NGX_MODULE_V1,
        &ngx_rtmp_module_ctx,                  /* module context */
        ngx_rtmp_commands,                     /* module directives */
        NGX_CORE_MODULE,                       /* module type */
        NULL,                                  /* init master */
        NULL,                                  /* init module */
        ngx_rtmp_init_process,                 /* init process */
        NULL,                                  /* init thread */
        NULL,                                  /* exit thread */
        NULL,                                  /* exit process */
        NULL,                                  /* exit master */
        NGX_MODULE_V1_PADDING
    };
    ``` 
* 在nginx-rtmp-module目录中,有个一config文件.
  ```shell
  ./configure --add-module=/path/to/nginx-rtmp-module
  ```
  这一步过程中,会读取config文件,生成*objs/src/ngx_modules.c*代码文件.
  文件中有如下结构体,
  ```c
  ngx_module_t *ngx_modules[] = {
    &ngx_core_module,
    &ngx_errlog_module,
    &ngx_conf_module,
    &ngx_rtmp_module,
    &ngx_rtmp_core_module,
    &ngx_rtmp_cmd_module,
    &ngx_rtmp_codec_module,
    &ngx_rtmp_access_module,
    &ngx_rtmp_record_module,
    &ngx_rtmp_live_module,
    &ngx_rtmp_play_module,
    &ngx_rtmp_flv_module,
    &ngx_rtmp_mp4_module,
    &ngx_rtmp_netcall_module,
    &ngx_rtmp_relay_module,
    &ngx_rtmp_exec_module,
    &ngx_rtmp_auto_push_module,
    &ngx_rtmp_notify_module,
    &ngx_rtmp_log_module,
    &ngx_rtmp_limit_module,
    &ngx_rtmp_hls_module,
    &ngx_rtmp_dash_module,
    &ngx_openssl_module,
    &ngx_regex_module,
    &ngx_events_module,
    &ngx_event_core_module,
    &ngx_epoll_module,
    ...
    NULL
  };
  ```
  这个数组,在xxxx时,会被复制到**ngx_cycle_t**中,

* 程序运行首先是初始化,初始化有
  <<>>中@4.3.4 解析配置流程
  1.根据配置文件所做的初始化.
    * ngx_rtmp_module实例中的commands,定义了"rtmp"的command,*set*指针指向函数*ngx_rtmp_block*.

  2.调用模块(**ngx_module_t**)定义的初始化函数(init_module,init_process,init_thread)的初始化.

  nginx读取配置文件,根据其中的配置项,初始化相应的数据结构.
  通过调用**ngx_module_t**的init_module()函数.
  看调用流程的最好方式还是Debug代码,或者至少有一份Log,纯看代码,在不熟悉的情况下,比较难.
  所以纯看代码的阶段,就主要来了解一下数据结构.

* 在初始化好,idle之后,如果有client连过来,最先执行的是哪行代码?
  * 那首先要找到哪个|socket|复制|accept| |1935|这个端口?
  * Nginx如果想要|监听|一个端口,是怎么个流程?异步IO?
  