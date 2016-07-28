#EGL文档翻译(1.4)

#1. Overview
>This document describes EGL, an interface between rendering APIs such as
OpenGL , OpenGL ES or OpenVG (referred to collectively as client APIs ) and
an underlying native platform window system. It refers to concepts discussed in
the OpenGL , OpenGL ES and OpenVG specifications, and should be read to-
gether with those documents. EGL uses OpenGL ES conventions for naming entry
points and macros.

>EGL provides mechanisms for creating rendering surfaces onto which client
APIs can draw, creating graphics contexts for client APIs , and synchronizing
drawing by client APIs as well as native platform rendering APIs. EGL does not
explicitly support remote or indirect rendering, unlike the similar GLX API.

EGL封装了底层Native平台的Window系统接口,为Rendering API提供标准接口.
文档里用了OpenGL ES中的术语.
EGL提供创建rendering surface的创建方法.
1. client APIs 可以draw
2. 创建graphics contexts
3. 同步的drawing
EGL不严格支持remote或间接rendering,这一个与GLX API不同.

##2.1 Native Window System 和 Rendering API
>EGL is intended to be implementable on multiple operating systems (such as Sym-
bian, embedded Linux, Unix, and Windows) and native window systems (such as
X and Microsoft Windows). Implementations may also choose to allow rendering
into specific types of EGL surfaces via other supported native rendering APIs, such
as Xlib or GDI. Native rendering is described in more detail in section 2.2.3.

EGL希望能够在不同的操作系统和Native窗口系统上能够实现.
EGL实现也可以通过支持native的渲染API,选择允许渲染到不通类型的EGL surfaces上,像Xlib或GDI.
Native渲染在2.2.3上详细介绍.

>To the extent possible, EGL itself is independent of definitions and concepts
specific to any native window system or rendering API. However, there are a few
places where native concepts must be mapped into EGL-specific concepts, includ-
ing the definition of the display on which graphics are drawn, and the definition of
native windows and pixmaps which can also support client API rendering.

为了扩展性, EGL本身有独立的definitions和concepts,与任何native window系统或rendering API.
但是,有一些native concepts比与和EGL的概念映射上,包括drawn图形的display的定义,和native window的定义.
pixmaps的定义,pixmaps也可以支持client API 渲染.

###2.1.1 Scalar Types
EGLBoolean EGL_TRUE(1), EGL_FALSE(0).
EGLint, 从1.4开始,EGLint的大小 >= native的int.
注意指针类型大小问题.

###2.1.2 Displays
Most EGL calls include an EGLDisplay parameter. This represents the abstract
display on which graphics are drawn. In most environments a display corresponds
to a single physical screen. The initialization routines described in section 3.2
include a method for querying a default display, and platform-specific EGL exten-
sions may be defined to obtain other displays.
All EGL objects are associated with an EGLDisplay, and exist in a names-
pace defined by that display. Objects are always specified by the combination of an
EGLDisplay parameter with a parameter representing the handle of the object.

大部分EGL调用都有一个EGLDisplay参数.代表了抽象的图形画的地方.
在大部分环境下,一个display与一个物理屏幕是绑定的.
这个初始化方法在3.2介绍.
查讯默认Display的方法,和平台制定的EGL extensions可以定义来获取其他的display.
所有的EGL对象都关联着一个EGLDisplay,且存在这一个由display定义的namespace.
这些对象总是由 一个EGLDisplay参数和一个object的Handle 来指定.

##2.2 Rendering Contexts and Drawing Surfaces
>The client API specifications are intentionally vague on how a rendering context
(e.g. the state machine defined by a client API ) is created. One of the purposes
of EGL is to provide a means to create client API rendering contexts (henceforth
simply referred to as contexts), and associate them with drawing surfaces.

client API文档故意含糊地讲rendering context是怎么创建的(例如client API的状态机).
EGL的目的之一就是提供一个创建client API rendering context的方法,和把contexts与drawing surfaces关联上.

>EGL defines several types of drawing surfaces collectively referred to as
EGLSurfaces. These include windows, used for onscreen rendering; pbuffers,
used for offscreen rendering; and pixmaps, used for offscreen rendering into buffers
that may be accessed through native APIs. EGL windows and pixmaps are tied to
native window system windows and pixmaps.

EGL定义了集中类型的drawing surfaces,叫做EGLSurfaces.
1. windows, onscreen rendering.
2. pbuffers, 用来 offscreen rendering.
3. pixmaps, offscreen rendering 到 native APIs能访问的buffers.
EGL windows和pixmaps是 被native windows system windows和pixmaps绑定的.

>EGLSurfaces are created with respect to an EGLConfig. The EGLConfig
describes the depth of the color buffer components and the types, quantities and
sizes of the ancillary buffers (i.e., the depth, multisample, and stencil buffers).

EGLSurfaces是根据EGLConfig创建的.
EGLConfig描述了depth of the color buffer components.
ancillary buffers(depth,multisample,stencil buffers)的类型,数量,大小.

>Ancillary buffers are associated with an EGLSurface, not with a context. If
several contexts are all writing to the same surface, they will share those buffers.
Rendering operations to one window never affect the unobscured pixels of another
window, or the corresponding pixels of ancillary buffers of that window.

辅助buffers关联EGLSurface, 与context不相关.
如果有几个contexts都在写到同一个surface, 他们会共享这些buffers.
一个window的渲染操作从来不会影响另一个window的unobscured pixels,相应的辅助buffers的像素.

＞Contexts for different client APIs all share the color buffer of a surface, but
ancillary buffers are not necessarily meaningful for every client API . In particular,
depth, multisample, and stencil buffers are currently used only by OpenGL and
OpenGL ES .

不同client APIs的contexts都共享一个surface的color buffer.
但是辅助buffer不是必要有意义,对每个client API.
部分depth,multisample,stencil buffers现在只被OpenGL和OpenGL ES用到.

>A context can be used with any EGLSurface that it is compatible with (sub-
ject to the restrictions discussed in the section on address space). A surface and
context are compatible if

context可以和任何兼容的EGLSurface合作(地址空间?).
surface和context在以下的情况中是兼容.

> • They support the same type of color buffer (RGB or luminance).
• They have color buffers and ancillary buffers of the same depth.
Depth is measured per-component. For example, color buffers in RGB565
and RGBA4444 formats have the same aggregate depth of 16 bits/pixel, but
are not compatible because their per-component depths are different.
Ancillary buffers not meaningful to a client API do not affect compatibility;
for example, a surface with both color and stencil buffers will be compat-
ible with an OpenVG context so long as the color buffers associated with
the contexts are of the same depth. The stencil buffer is irrelevant because
OpenVG does not use it.
• The surface was created with respect to an EGLConfig supporting client
API rendering of the same type as the API type of the context (in environ-
ments supporting multiple client APIs ).
• They were created with respect to the same EGLDisplay (in environments
supporting multiple displays).

* 支持同一种格式的color buffer
* 他们有相同的color buffers和相同depth的辅助buffers
  Depth是每个组件计算的.比如过color buffers是RGB565和RGB4444格式的有相同的16 bits/pixel的depth.
  但是不兼容,因为每个组件的depths是不一样的.
  辅助buffers由于非每个client API不影响兼容.
  比如说surface有着同样的color和stencil buffers会兼容OpenVG context,只要color buffer关联的context是一个depth.
  OpenVG不需要用stencil buffer.
* 创建surface的EGLConfig支持client API 渲染到相同类型的context API类型.
* 他们在相同的EGLDisplay下创建.

>As long as the compatibility constraint and the address space requirement are
satisfied, clients can render into the same EGLSurface using different contexts.
It is also possible to use a single context to render into multiple EGLSurfaces.

只要这些兼容约束满足,且地址空间要求满足,clients可以渲染到同一个EGLSurface用不同的contexts.
也可以用同一个context去渲染不通的EGLSurfaces.

2.2.1 Using Rendering Contexts
>OpenGL and OpenGL ES define both client state and server state. Thus an
OpenGL or OpenGL ES context consists of two parts: one to hold the client state
and one to hold the server state. OpenVG does not separate client and server state.

>The OpenGL , OpenGL ES , and OpenVG client APIs rely on an implicit con-
text used by all entry points, rather than passing an explicit context parameter. The
implicit context for each API is set with EGL calls (see section 3.7.3). The implicit
contexts used by these APIs are called current contexts.

OpengGL和OpenGL ES 定义了不同的client状态和server状态.
所以OpenGL和OpenGl ES的context有两部分组成:
一个持有client状态和一个持有server状态.
OepnVG没有独立的client状态和server状态.

OpenGL,OpenGL ES,OpenVG client APIs依赖隐式context,在每个entry point,而不是传一个显式context参数.
每个API隐式的context,是有EGL调用设置的(eglMakeCurrent? 3.7.3).
隐式contexts被这些APIs称作挡墙的contexts.

>Each thread can have at most one current rendering context for each supported
client API ; for example, there may be both a current OpenGL ES context and
a current OpenVG context in an implementation supporting both of these APIs.
In addition, a context can be current to only one thread at a time. The client is
responsible for creating contexts and surfaces. Because OpenGL and OpenGL ES
contexts share many entry points, additional restrictions on current contexts exists
for these client APIs when both are supported (see section 3.7).

每个线程都可以有多个当前rendering contexrt,为每个对应的client API.
举例,他们可能同时有一个当前OpenGL ES context和一个当前OpenVG.如果实现支持的话.
一个线程在同一时刻只能有个当前context.
client负责创建context和surface.
因为OpenGL和OpenGL EScontext共享很多entry points,并且当前context限制存在这些client APIs.

2.2.2 Rendering Models
>EGL, OpenGL , and OpenGL ES support two rendering models: back buffered
and single buffered.
>Back buffered rendering is used by window and pbuffer surfaces. Memory for
the color buffer used during rendering is allocated and owned by EGL. When the
client is finished drawing a frame, the back buffer may be copied to a visible win-
dow using eglSwapBuffers. Pbuffer surfaces have a back buffer but no associated
window, so the back buffer need not be copied.

EGL, OpenGL, OpenGL ES,支持两种渲染模型, back buffered和 single buffered.
Back buffered 渲染在window和pbuffer Surfaces的用.
color buffer在渲染时的内存又EGL创建和管理.
当client结束一帧的draw时, back buffer可能复制到一个科技安的window用*eglSwapBuffers*.
pbuffer surfaces 有个back buffer但是不关联window,所以back buffer不需要复制到window上.

>Single buffered rendering is used by pixmap surfaces. Memory for the color
buffer is specified at surface creation time in the form of a native pixmap, and
client APIs are required to use that memory during rendering. When the client
is finished drawing a frame, the native pixmap contains the final image. Pixmap
surfaces typically do not support multisampling, since the native pixmap used as
the color buffer is unlikely to provide space to store multisample information.


>Some client APIs , such as OpenGL and OpenVG , also support single buffered
rendering to window surfaces. This behavior can be selected when creating the
window surface, as defined in section 3.5.1. When mixing use of client APIs which
do not support single buffered rendering into windows, like OpenGL ES , with
client APIs which do support it, back color buffers and visible window contents
must be kept consistent when binding window surfaces to contexts for each API
type (see section 3.7.3).

>Both back and single buffered surfaces may also be copied to a specified native
pixmap using eglCopyBuffers.