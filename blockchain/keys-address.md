[第四章](https://github.com/bitcoinbook/bitcoinbook/blob/develop/ch04.asciidoc)

digital signatures

generated with a secret key

Keys come in pairs consisting of a private (secret) key and a public key.


In most cases, a bitcoin address is generated from and corresponds to a public key

比特币地址 与 一个公钥是绑定的。
比特币地址 脚本

prime number exponentiation 
素数求幂
椭圆曲线乘法

The public key is used to receive funds, and the private key is used to sign transactions to spend the funds.
公钥用来收钱，私钥用来付钱

The private key (k) is a number, usually picked at random.
私钥通常就是一个随机数,256bit,0~2-256-1

From the private key, we use elliptic curve multiplication, a one-way cryptographic function, to generate a public key (K).
通过私钥，我们用椭圆曲线乘法，
[!](https://github.com/bitcoinbook/bitcoinbook/raw/develop/images/mbc2_0401.png)

The public key is calculated from the private key using elliptic curve multiplication, which is irreversible: K = k * G, where k is the private key, G is a constant point called the generator point, and K is the resulting public key
公钥
K = k * G




节点是如何验证交易的?

首先，

比特币的数量是在块上的。总量是每10分钟，增加一个块，每块有固定的比特币数量。

交易，就是从A的账户里，划多少多少btc到B的账户里。

块的数据结构是：



lock llll lllll lllll

unlock lll ，lll

