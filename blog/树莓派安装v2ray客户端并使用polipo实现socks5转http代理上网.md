## 树莓派安装v2ray客户端并使用polipo实现socks5转http代理上网

### **一、安装V2ray**

 V2Ray 是一个与 Shadowsocks 类似的代理软件，可以用来科学上网（翻墙）学习国外先进科学技术。 

 **首先你需要一台服务器,配置v2ray服务器端，推荐使用[一键脚本](https://github.com/233boy/v2ray)** ，或者使用别人的链接

 首先下载脚本： 

```shel
wget https://install.direct/go.sh
```

然后执行脚本安装V2Ray：（可能脚本下载软件慢，建议先下载好软件，然后修改脚本本地安装）

```
sudo bash go.sh
```

 使用以下命令启动 V2Ray: 

```shell
sudo systemctl start v2ray
```

 停止运行 V2Ray： 

```shell
sudo systemctl stop v2ray
```

 重启 V2Ray: 

```shell
sudo systemctl restart v2ray
```

在安装完 V2Ray 之后，修改配置文件重启 V2Ray 即可，配置文件路径为 /etc/v2ray/config.json。

更新 V2Ray 的方法是再次执行安装脚本。安装脚本更多使用方法可以执行`bash go.sh -h`看帮助



V2ray配置：建议在windows下使用客户端配置好之后，将config文件复制一份到树莓派下。



### **二、安装polipo软件**

 Polipo 是一个小而快速的缓存 web 代理程序(web 缓存, HTTP 代理, 代理服务器)，可以将 socks5代理转换为 http 代理 

配置文件在：/etc/polipo/config

在配置文件中新增：

```shell
socksParentProxy = "127.0.0.1:10808"
socksProxyType = socks5
proxyAddress = "0.0.0.0"
proxyPort = 10809
```

重启polipo：

```shell
sudo /etc/init.d/polipo restart
```

