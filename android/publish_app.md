##签名
所有APKs都是被一个证书签名过的,才能被安装到Android设备上.
包括,
* 用Android Studio签名APK.
* 创建和存放你的证书
* 对每个不同的配置用不同的证书
* 配置构建过程来自动给APK签名

签名和钥匙库
一个publick-key证书,又叫数字证书或identity证书,
包含了一个public-key,它是一个公/私钥对的公开部分
.还有别的拥有者的信息,像姓名,地址.
证书的拥有者拥有对应的私钥.
当你对APK签名时,签名工具把公钥放在APK里.
公钥相当与指纹,单一关联APK和你的私钥.
这样帮助Android保证任何未来对APK的更新是认证过的,保证来自作者.

一个钥匙库是一个二进制文件.包含有1到多个私钥.
当你用Android Studio对要发布的APK签名时,你可以选择生成一个新的keystore和私钥,
也可以用已经存在的.
你应该选择一个健壮的密码给你的钥匙库,一个独立健壮的密码为每个私钥.
你必须保存私钥在一个安全的地方.

对一个app,你永远只能用一个证书,保证用户可以更新.[这里讲为什么](https://developer.android.com/studio/publish/app-signing.html#considerations)

#为调试版签名
Android Studio会自动用`debug.keystore`给签名

Debug证书是build tools生成的, 并不安全?,大部分应用商店不会允许用Debug证书签名的APK发布.

Debug证书只有一年有效期,出错的时候把那个keystore删除,会自动生成新的.

#为正式版签名
可以用Android Studio来手动生成签名的APK, 对不同的编译选项.
也可以配置Gradle,在构建过程中自动签名.

#保护你的私钥
用Android Studio配置的最后
Gradle会把你的配置直接写到build.gradle里,你可以通过
~~~~来把它独立到别的文件里.

#也可以通过命令行来签名

#keytool常用的功能