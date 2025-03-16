 **PRIVATE** ：私有的。生成 libhello-world.so时，只在 hello_world.c 中包含了 hello.h，libhello-world.so **对外**的头文件——hello_world.h 中不包含 hello.h。而且 main.c 不会调用 hello.c 中的函数，或者说 main.c 不知道 hello.c 的存在，那么在 hello-world/CMakeLists.txt 中应该写入：

```cmake
target_link_libraries(hello-world PRIVATE hello)
target_include_directories(hello-world PRIVATE hello)
```

 **INTERFACE** ：接口。生成 libhello-world.so 时，只在libhello-world.so **对外**的头文件——hello_world.h 中包含 了 hello.h， hello_world.c 中不包含 hello.h，即 libhello-world.so 不使用 libhello.so 提供的功能，只使用 hello.h 中的某些信息，比如结构体。但是 main.c 需要使用 libhello.so 中的功能。那么在 hello-world/CMakeLists.txt 中应该写入：

```cmake
target_link_libraries(hello-world INTERFACE hello)
target_include_directories(hello-world INTERFACE hello)
```

 **PUBLIC** ：公开的。 **PUBLIC = PRIVATE + INTERFACE** 。生成 libhello-world.so 时，在 hello_world.c 和 hello_world.h 中都包含了 hello.h。并且 main.c 中也需要使用 libhello.so 提供的功能。那么在 hello-world/CMakeLists.txt 中应该写入：

```cmake
target_link_libraries(hello-world PUBLIC hello)
target_include_directories(hello-world PUBLIC hello)
```

实际上，这三个关键字指定的是目标文件依赖项的使用 **范围（scope）** 或者一种 **传递（propagate）** 。[官方说明](https://link.zhihu.com/?target=https%3A//cmake.org/cmake/help/v3.15/manual/cmake-buildsystem.7.html%23transitive-usage-requirements)

可执行文件依赖 libhello-world.so， libhello-world.so 依赖 libhello.so 和 libworld.so。

1. main.c 不使用 libhello.so 的任何功能，因此 libhello-world.so 不需要将其依赖—— libhello.so 传递给 main.c，hello-world/CMakeLists.txt 中使用 PRIVATE 关键字；
2. main.c 使用 libhello.so 的功能，但是libhello-world.so 不使用，hello-world/CMakeLists.txt 中使用 INTERFACE 关键字；
3. main.c 和 libhello-world.so 都使用 libhello.so 的功能，hello-world/CMakeLists.txt 中使用 PUBLIC 关键字；
