###HLS文档
* [HLS on Apple](https://developer.apple.com/streaming/)
* [Overview](https://developer.apple.com/library/ios/documentation/NetworkingInternet/Conceptual/StreamingMediaGuide/Introduction/Introduction.html#//apple_ref/doc/uid/TP40008332-CH1-SW1)

###协议草稿
[HTTP Live Streaming](https://tools.ietf.org/html/draft-pantos-http-live-streaming-19)

###m3u8文件

###同事的总结
> #ExoPlayerHLS方面

通过看代码和执行程序，得到的流程

* 创建parse:HlsPlaylistParser
* 创建playlistFetcher:ManifestFetcher<HlsPlaylist>，将parse\URI\UriDataSource传入
* 执行singleLoad()方法，并且传入callback和mainLooper（callback继承onSingleManifest()方法，当
* 创建fetchHelper:SingleFetchHelper(new一个singleUseLoader:loader)，传入UriLoadable<>(new 传
入uri\uriDataSource\parser)\callbackLooper\callback,并且startLoading
* 获取开始时间戳，singleUseLoader执行startloading,传入UriLoadable<>\callback\looper
* 创建LoadTask（传入looper\loadable\callback），并且提交到downloadExecutorService，并执行子线
程run方法
* 解析uri，执行UriLoadable中的load()方法


##解析第一层m3u8文件


* 调用HlsPlaylistParser中的parse方法将baseURI和获取到的输入流（uri中的m3u8流）传入
* 逐行解析u3u8中的一部分，并添加到extraLines，若是#EXT-X-STREAM-INF开头则返回一个new出来的
parseMasterPlaylist
* 在parseMasterPlaylist中，传入之前解析的条目和整个输入流，并且逐条解析，获取到下一条地址的
bitrate\codecs\name\resolutiuonString，并且在解析地址的时候，将这些信息加入format中，并添加到
variants的ArrayList中，解析完所有的，并返回一个HlsMasterPlaylist，传入解析好的
variants:ArrayList等信息。
* 发送消息解析完毕，回调ManigestFetcher中SingleFetchHelper类的onLoadCompleted方法
* 此时这个东西返回到loadable中的result:HlsPlaylisy属性中
* 然后回调MainActivity中的onSingleManifest方法，将result:HlsPlaylisy传入（result中带有
variants:ArrayList,里面带有各种信息）。

###Example多码率的
其中一条为

    #EXT-X-STREAM-INF:PROGRAM-ID=1,BANDWIDTH=232370,CODECS="mp4a.40.2, avc1.4d4015"
    gear1/prog_index.m3u8

一个流文件中，先解析到#EXT-X-STREAM-INF，然后把bandwidth、codecs解析出来，然后下一条读到

gear1/prog_index.m3u8时，将上一条解析到的信息存到format中，将format和line一起加入到一个设定好

的arrayList中去，每条码率的都这样做。然后将所有解析到的传入new HlsMasterPlaylist并返回出去


###继续代码步骤
* 进入MainActivity中，将解析到的HlsMasterPlaylist传入HlsChunkSource，HlsChunkSource传入HlsSampleSource。
* 然后将HlsSampleSource传入MediaCodecVideoTrackRenderer
* MediaCodecVideoTrackRenderer初始化的时候调用register方法注册,HlsSampleSource注册（注册音频和视频）
* 之后将MediaCodecVideoTrackRenderer传入ExoPlayer.prepare()
* ExoPlayer.sendMessage()
* 相继HlsSampleSource.prepare();HlsChunkSource.prepare();
* 之后HlsChunkSource在prepare过程中(传入的trackSelector为DefaultHlsTrackSelector),trackSelector调用selectTracks()
* 期间，通过顺序依次调用HlsChunkSource中的adaptiveTrack(),compare(),fixedTrack(),selectTrack选择合适的源文件
* 
* HlsSampleSource在prepare过程中调用maybeStartLoading(),getNextLoadPositionUs(),isPendingReset()
* 在期间调用了HlsChunkSource中的getChunkOperation()方法清楚更新{@链接chunkoperationholder }的下一步操作
* 期间继续调用getNextVariantIndex(),因为mediaPlayList为空，所以调用newMediaPlaylistChunk()来创建一个新的mediaPlayList，直接返回。
* 继续执行maybeStartLoading()接下去的部分,因为之前传入的uri(封装在chunk中)为第二层m3u8的chunk，调用isTschunk()后，为否，继续执行。
* 调用notifyLoadStarted()，最后调用Loader.startLoading()
* 之后循环准备加载需要的东西，直到加载完，结束，startLoading()继续执行
* MediaPlaylistChunk.consume调用，将HlsMasterPlaylist解析到的下一个m3u8地址下载

###解析第二层m3u8文件

* 执行HlsPlaylistParser中的parse方法，传入baseURI和输入流（下载的m3u8流）
* 若流为#EXT-X-TARGETDURATION开头，返回一个new parseMediaPlaylist，并传入上面提到的整个输入流
* parseMediaPlaylist中，逐条解析，把version等等信息解析出来，碰到#EXTINF开头的标签解析出targetDurationSecs，和下一条ts文件的路径，加入segmentL:ArrayList
* 此List中保存着什么时候播放什么ts流等等信息，传入parseMediaPlaylist并返回给consume()

###Example
其中为

	#EXTM3U
	#EXT-X-TARGETDURATION:10
	#EXT-X-VERSION:3
	#EXT-X-MEDIA-SEQUENCE:0
	#EXT-X-PLAYLIST-TYPE:VOD
	#EXTINF:9.97667,	
	fileSequence0.ts
	#EXTINF:9.97667,	
	fileSequence1.ts
	
	……
	
	#EXTINF:4.20333,	
	fileSequence180.ts
	#EXT-X-ENDLIST

先解析这部分part1
	
	#EXTM3U
	#EXT-X-TARGETDURATION:10
	#EXT-X-VERSION:3
	#EXT-X-MEDIA-SEQUENCE:0
	#EXT-X-PLAYLIST-TYPE:VOD//代码里面这条不用解析。

一条条将这几条信息先解析出来，然后解析下一部分part2

	#EXTINF:9.97667,	
	fileSequence0.ts
	#EXTINF:9.97667,	
	fileSequence1.ts
	
	……
	
	#EXTINF:4.20333,	
	fileSequence180.ts
	#EXT-X-ENDLIST

先读取这个片段的时间，
然后解析下一条，读取，片段计数器+1，计算这个片段的开始时间、结束时间等等等等信息
然后new一个segment并传入，然后加入segments:ArrayList
等全部读完，将part1读取到的信息和part2读取到的segments等信息传入一个new HlsMediaPlaylist中并
返回


* 此时整个HLS头文件解析完毕。
* 之后直接回调HlsSimpleSource.onLoadCompleted(),HlsChunkSource.onChunkLoadCompleted()
* 调用HlsChunkSource.setMediaPlaylist()，把获取到的HlsMediaPlayList加入variantPlaylists:ArrayList
* HlsSimpleSource中，相继调用notifyLoadCompleted(),clearCurrentLoadable(),maybeStartLoading().
* 然后在后续执行过程中，先分析到到需要播放的ts流
* 调用HlsChunkSource中的getChunkOperation
* 在此过程中创建dataSpec:dataspec,传入uri和segment中的，再解析到各种信息，全部封装到TsChunk中，传到输出的chunk中。
* 一个segment创建一个chunk，等要播放的时候创建，然后拿出来用就行了


可能有不对的地方，不过大体上就是这样

盗图，跟后面MasterPlayList传入后解析的流程图大同小异
![解析源的流程图](http://img.blog.csdn.net/20160523120350784)

![Hls相关类图](http://a2.qpic.cn/psb?/V10YSJGH26Unvn/Y.BXCKLqnFOqso3*ge.3pBe0O*nANb1JyfiIVQkpLVg!/b/dHEBAAAAAAAA&ek=1&kp=1&pt=0&bo=vQOAAsYDhgIFAF4!&su=1181166433&sce=0-12-12&rf=2-9)
不知道对不对，自己的理解的，而且类图学了好久了。



然后ExoPlayer的类图，网上盗图
![ExpPlayer](http://upload-images.jianshu.io/upload_images/599109-15ca46f89f405d04.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


#7-22HLS默认流和播放时的动态选择
#动态选择流过程

##默认流的选择

* HlsChunkSource初始化的时候传入一个DefaultHlsTrackSelector.newDefaultInstance(Context)//代表选择器所选择的流是playlist
* 在HlsChunkSource.prepare中调用DefalutHlsTrackSelector.selectTracks,传入HlsMasterPlaylist(保存着各种流信息)\Output输出的流信息
* 调用VideoFormatSelectorUtil.selectVideoFormatsForDefaultDisplay(),传入playlist从多个视频格式中选择一个合适的子集，将呈现在设备的默认显示上。
 * 这个过程中先调用VideoFormatSelectorUtil.getViewportSize()获取屏幕的分辨率,然后将分辨率\Playlist传入VideoFormatSelectorUtil.selectVideoFormats()并调用
 * 查询Playlist中每一条数据，并调用isFormatPlayable(),先判断格式是否能播放(检查编码)，若是，添加到ArrayList中
 * 筛选出在显示屏分辨率范围内最大能播放的分辨率的编码(若视频分辨率大于设备分辨，无意义，浪费资源)然后移除不必要的分辨率（大于显示屏分辨率的）并返回
* 再从筛选出来的流中视频流和音频流，留下视频流
* 然后调用HlsChunkList中的adaptiveTrack()，将流按照带宽来排序流，降序
* 逐个循环码率，找到最大分辨率的码率，把这个码率add到tracks:List中去
* 然后每条码率都调用fixedTrack()，将每条码率都以ExposedTrack封装，添加到tracks:List中去
* 现在是第一条为默认码率，其他都是按照带宽降序排列
* 然后调用HlsChunkList中的fixedTrack(),传入参数0，代表选择的码率为第一条(默认码率)


##播放中动态选择

* 在HlsChunkSource中，选择Selector模式为剪接模式，HlsChunkSource.getChunkOperation()中，调用getNextVariantIndex()传入前面播放的TsChunk，播放的位置
* 估算比特率，如果前一TsChunk为空(前面未播放)，则直接调用之前选择的流
* 若不为空，则判断比特率，与选择相符，则继续使用此流，若不相符，则检查有没有相符的流，若有，返回相符的流的Index，若没有，继续使用当前的流。
* 然后使用上一步骤返回的Index解析流，若上一次的流已经封装好，则直接使用，若否，则创建MediaPlaylistChunk(一条合适的流信息全都保存在这里)并返回
* 开始解析第一个流的文件，解析完后返回，回调HlsSampleSource.onLoadCompleted()
* 调用HlsChunkSource.onChunkLoadCompleted(),调用setMediaPlaylist()将读取到的信息写入
* 
* 调用HlsChunkSource.getChunkOperation(),HlsChunkSource.getNextVariantIndex(),流程和上面的解析一样
* 
* 然后判断到mediaPlaylist不为空，继续下面步骤，读取第一个ts文件地址，读取完各种信息后完封装为TsChunk设定为下一个要播放的片段
* 将这个tsChunk.extractorWrapper加入到extractors:LinkList<>，然后下载加载这个片段


//下面应该是播放的事情了，不是筛选的事情，所以看的不是很清晰

* 等待第一个码率流文件解析完成，调用buildTracks(传入LinkList)
* 期间，将各条流(未解析的其他码率的流)的各种信息返回给trackFormats:MediaFormat[]，并保存
* 之后回调getFormat,getTrackCount，回调enable()
* 期间，调用setTrackEnabledState标记流可不可用，当标记为可用，回调continueBuffering()，判断流是否可用
* 继续读取并显示在界面上

##总结
大概的流程应该就是这样，主要是选择下一ts的时候getNextVariantIndex()来筛选应该放哪个流。根据bandwidth来判断



##流程图

###ExoPlayer中HLS流，默认流选择流程
![ExoPlayer中HLS流，默认流选择流程](http://a2.qpic.cn/psb?/V10YSJGH26Unvn/uIPTIXhtHXW2ENV2UcEIr..8.ZNU3ryWo2VcBFiLYRg!/b/dI0BAAAAAAAA&ek=1&kp=1&pt=0&bo=VgWAAlgNQAYFAOE!&su=113432529&sce=0-12-12&rf=2-9)


###ExoPlayer中HLS流，动态流选择流程 
![ExoPlayer中HLS流，动态流选择流程](http://a4.qpic.cn/psb?/V10YSJGH26Unvn/KV*AXx1jDzM8q.X.RM*OcGSGF3q6mIsTXZzkUjbcJNM!/b/dI8BAAAAAAAA&ek=1&kp=1&pt=0&bo=5ASAAkAGMgMFADY!&su=1109216481&sce=0-12-12&rf=2-9)

