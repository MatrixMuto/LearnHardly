
###在AOSP环境里编译
最早的时候,我们直接在源码环境里去编译,因为会用到那时ndk中不能提供的库

###ndk-build
* 最多的用法都是ndk-build
* 复杂一些的是standalone的用法

###[Standalone Toolchain](https://developer.android.com/ndk/guides/standalone_toolchain.html)
以下方式:
* Simple Method
```
SYSROOT=$NDK/platforms/android-21/arch-arm
```
```
export CC="$NDK/toolchains/arm-linux-androideabi-4.8/prebuilt/ \
linux-x86/bin/arm-linux-androideabi-gcc-4.8 --sysroot=$SYSROOT"
$CC -o foo.o -c foo.c
```

* Advanced method
```
$NDK/build/tools/make-standalone-toolchain.sh \
--arch=arm --platform=android-21 --install-dir=/tmp/my-android-toolchain
```

额外注意的GCC编译器选项,
> If you want to target the armeabi-v7a ABI, you must set the following flags:
CFLAGS= -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16

To use NEON instructions, you must change the -mfpu compiler flag:
CFLAGS= -march=armv7-a -mfloat-abi=softfp -mfpu=neon

Also, make sure to provide the following two flags to the linker:
LDFLAGS= -march=armv7-a -Wl,--fix-cortex-a8

基础: gcc, link过程


###Android NDK Sample
[googlesamples/android-ndk](https://github.com/googlesamples/android-ndk)

