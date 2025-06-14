# breakpad

Breakpad是一个比Linux core机制更强大的、用于记录程序崩溃时信息的工具套件，可用来查看被strip，也就是被剔除了编译器调试信息的应用程序的崩溃信息。在程序崩溃时，将崩溃信息记录在一个小巧的“ minidump”文件中，将其发送回服务器。并且可以从这些minidump和符号文件来生成C和C++堆栈跟踪。


# 使用方式

```bash

#1.编译程序，加-g选项
cmake .. -DCMAKE_BUILD_TYPE=DEBUG && make

#2.执行命令生成xxx.dump
./breakpad_example 
# 生成 /tmp/72041f18-93fc-421c-9750fd90-b15727ee.dmp

#3.生成xxx.sym
dump_syms breakpad_example > breakpad_example.sym

#4，查看生成的sym
$ head -n 1 breakpad_example.sym
$ MODULE Linux x86_64 1DD0C19364A8A9FFBA5B6D8FA7F6DF4C0 breakpad_example

#5.存储sym
mkdir -p ./symbols/breakpad_example/1DD0C19364A8A9FFBA5B6D8FA7F6DF4C0 
cp breakpad_example.sym ./symbols/breakpad_example/1DD0C19364A8A9FFBA5B6D8FA7F6DF4C0 

#6.分析
minidump_stackwalk /tmp/72041f18-93fc-421c-9750fd90-b15727ee.dmp ./symbols
# 这个命令会打印很多内容，部分如下
2025-06-14 16:38:41: minidump_processor.cc:407: INFO: Processed /tmp/72041f18-93fc-421c-9750fd90-b15727ee.dmp
Operating system: Linux
                  0.0.0 Linux 5.13.0-30-generic #33~20.04.1 SMP Mon Mar 7 19:23:39 CST 2022 x86_64
CPU: amd64
     family 6 model 158 stepping 12
     1 CPU

GPU: UNKNOWN

Crash reason:  SIGSEGV /SEGV_MAPERR
Crash address: 0x0
Process uptime: not available

Thread 0 (crashed)
 0  breakpad_example!CoreFun(int*) [main.cpp : 10 + 0x4]
    rax = 0x0000000000000000   rdx = 0x0000000000000000
    rcx = 0x00007ffcfa853530   rbx = 0x00005600ac9b8d60
    rsi = 0x0000000000000000   rdi = 0x0000000000000000
    rbp = 0x00007ffcfa853580   rsp = 0x00007ffcfa853580
     r8 = 0x0000000000000000    r9 = 0x00005600ae2ee388
    r10 = 0x0000000000000008   r11 = 0x00007f6e92a31be0
    r12 = 0x00005600ac97c850   r13 = 0x00007ffcfa853830
    r14 = 0x0000000000000000   r15 = 0x0000000000000000
    rip = 0x00005600ac97c988
    Found by: given as instruction pointer in context


#7.可以转成core进行分析
minidump-2-core -v  /tmp/72041f18-93fc-421c-9750fd90-b15727ee.dmp -o core.1

```