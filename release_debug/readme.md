# ReleaseDebug

## cmake_build_type=Release

源码中什么编译选项都没加，执行cmake的时候添加参数：-DCMAKE_BUILD_TYPE=Release，发现最后编译的命令：

```
bash
/usr/bin/c++ -O3 -DNDEBUG CMakeFiles/release_debug.dir/src/hello.cpp.o CMakeFiles/release_debug.dir/src/main.cpp.o -o release_debug
```

可以看见直接开启最大的优化了

## cmake_build_type=Debug

源码中什么编译选项都没加，执行cmake的时候添加参数：-DCMAKE_BUILD_TYPE=Release，发现最后编译的命令：

```
bash
/usr/bin/c++ -g CMakeFiles/release_debug.dir/src/hello.cpp.o CMakeFiles/release_debug.dir/src/main.cpp.o -o release_debug
```

编译命令增加了 `-g`
