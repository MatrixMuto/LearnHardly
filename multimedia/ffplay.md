1. 初始化过程
is = stream_open(input_filename, file_iformat);
#### 函数stream_open
init frame队列 解码好的数据 (pictq, subpq, sampq)
init packet队列 未解码的数据(videoq,audioq,subtitleq)
init clock (video,audio,ext)
开启read_thread线程

####线程read_thread:
    
- 初始化
    AVFormatContext *ic = NULL;
    ic = avformat_alloc_context();

-  设置是否允许调用阻塞的方法
        ic->interrupt_callback.callback = decode_interrupt_cb;
        ic->interrupt_callback.opaque = is;

-   打开文件
       err = avformat_open_input(&ic, is->filename, is->iformat, &format_opts);
- 
        av_format_inject_global_side_data(is);

- 设置参数
        opts = setup_find_stream_info_opts(ic, codec_opts);
- 获取stream信息     
    err = avformat_find_stream_info(ic, opts);
    
2. 事件循环的过程

event_loop(is);
#### 函数event_loop中:
	   获取事件
	   refresh_loop_wait_event(cur_stream, &event);
#### 函数refresh_loop_wait_event中:
 初始化
 double remaining_time = 0.0;    
 
 在没有SDL事件的时候:
        if (remaining_time > 0.0)
            av_usleep((int64_t)(remaining_time * 1000000.0));
        remaining_time = REFRESH_RATE;
        if (is->show_mode != SHOW_MODE_NONE && (!is->paused || is->force_refresh))
            video_refresh(is, &remaining_time);
   
   估计video_refresh是去执行一个任务,并把它消耗的时间从remaining_time扣除.

#### 
    if (!is->paused && get_master_sync_type(is) == AV_SYNC_EXTERNAL_CLOCK && is->realtime)
        check_external_clock_speed(is);
 如果 非暂停 且 同步类型是EXT时钟 且 现在是实时播放, 就检查一下EXT时钟倍速.is->av_sync_type = av_sync_type;read_thread



#### avformat/mov.c
static int mov_read_default(MOVContext *c, AVIOContext *pb, MOVAtom atom)

atom代表当前的container
