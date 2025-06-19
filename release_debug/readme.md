# ReleaseDebug

## cmake_build_type=Release

源码中什么编译选项都没加，执行cmake的时候添加参数：-DCMAKE_BUILD_TYPE=Release，发现最后编译的命令：

```
bash
/usr/bin/c++ -O3 -DNDEBUG CMakeFiles/release_debug.dir/src/hello.cpp.o CMakeFiles/release_debug.dir/src/main.cpp.o -o release_debug
```

可以看见直接开启最大的优化了

## cmake_build_type=Debug

源码中什么编译选项都没加，执行cmake的时候添加参数：-DCMAKE_BUILD_TYPE=Debug，发现最后编译的命令：

```
bash
/usr/bin/c++ -g CMakeFiles/release_debug.dir/src/hello.cpp.o CMakeFiles/release_debug.dir/src/main.cpp.o -o release_debug
```

编译命令增加了 `-g`

## core调试

一般不可以使用debug版本的二进制，调试release版本生成的core文件：
* 1. release跟debug版本的二进制代码布局、优化、符号表都可能不同
* 2. core文件记录了release版本的内存映射和指令地址，debug版本无法正确映射这些地址到源码行
* 3. 可能会出现符号错位，变量值不对等问题
