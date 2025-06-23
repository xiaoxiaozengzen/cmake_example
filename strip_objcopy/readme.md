# Overview

# strip

```bash
# 1.提取二进制文件中的debug信息，二进制文件为release_debug，提取后的信息在release_debug.debug
objcopy --only-keep-debug release_debug release_debug.debug

# 2,strip当前二进制
strip release_debug

# 3.程序运行并生成core文件
ulimit -c unlimited && ./release_debug
 
# 4.调试目标加载分离的调试信息
objcopy --add-gnu-debuglink=./release_debug.debug release_debug

# 5.gdb调试程序
$ gdb release_debug core
```

# 上述第四步会在release_debug文件中加入一个特殊段，记录调试文件的文件名，例如：release_debug.debug
# 注意：
# * 程序只记录带debug信息的文件名字，而不去记录其完整路径
# * gdb会现在当前目录下找，找不到回去/usr/lib/debug查找
```bash
$ readelf -p .gnu_debuglink strip_objcopy_exe

String dump of section '.gnu_debuglink':
  [     0]  strip_objcopy_exe.debug
```

# gdb -x

`gdb -x gdbcommand.txt` 会自动读取文件内容，并按照文件所有命令进行执行