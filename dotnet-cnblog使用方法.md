# dotnet-cnblog使用方法

```shell
dotnet-cnblog proc -f 你要上传的md文档路径
```

***下面是原博客链接：***[https://www.cnblogs.com/dhan/p/18726302]()

# 安装dotnet

进入官网
[https://dotnet.microsoft.com/en-us/download/dotnet](https://dotnet.microsoft.com/en-us/download/dotnet)
展开这个框有老版本下载
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114808604-2095260839.png)
找到5.0点击进去
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114808182-1698400988.png)
按照需求下载即可，我是windows x64。
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114807719-823659922.png)
下载完成双击安装即可，过程中有让安装其他的话无脑同意即可。

# 检测是否安装成功

直接打开终端，输入下面命令

```shell
dotnet --info
```

版本一定要5才行
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114806621-1670213693.png)

# 安装dotnet-cnblog插件

同理版本一定要1.4.0才行

```shell
dotnet tool install -g --version 1.4.0 dotnet-cnblog
```

![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114806224-448175495.png)
如果你太心急安装了其他版本可以卸载，输入下面命令，然后再次运行上面的安装命令即可

```shell
dotnet tool uninstall dotnet-cnblog
```

# 第一次运行的配置

```shell
#输入
dotnet-cnblog
```

第一次运行需要配置，跟着提示填写即可
id提示你要填写博客园url的那个名字，用户名就是你博客园的用户名都很简单
注意最后那个密码不是你cnblog的登录密码，而是你个人设置中的访问token。
填写密码的时候，这里建议看下面的注意事项。
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114805899-1166113463.png)

# 自动上传图片到cnblog注意事项

设置中输入的密码 `不是你cnblog的密码`，而是你的cnblog博客设置里的=`token`=
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114805543-1124349214.png)
这个token进入账号设置->博客设置->其他设置中能找到， =第一次设置的话是没有token的= ，需要你去生成一个，点击生成就行了，然后点查看令牌就能拿token填入。
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114804686-129504492.png)
点击查看，里面那个令牌就是你在设置的时候要输入在 `"请输入密 码："`中，记住是输入这个token而不是cnblog的密码。
![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114804354-1556477003.png)

# 成功上传

接着输入命令

```shell
dotnet-cnblog proc -f 你要上传的md文档路径
```

![](https://img2023.cnblogs.com/blog/3392862/202502/3392862-20250220114803470-597175568.png)

然后他会在你这个文档同一目录下生成一个 `xxx-cnblog.md`文件，这个就是在他自动帮你上传了图片后，替换了你本地图片的路径，替换为cnblog的图床url路径。
