# Overview

```bash
# 提取二进制文件中的debug信息，二进制文件为release_debug，提取后的信息在release_debug.debug
objcopy --only-keep-debug release_debug release_debug.debug

# strip当前二进制
strip release_debug

# 程序运行并生成core文件
ulimit -c unlimited && ./release_debug
 
# 调试目标加载分离的调试信息
objcopy --add-gnu-debuglink=./release_debug.debug release_debug

# gdb调试程序
$ gdb release_debug core
```
