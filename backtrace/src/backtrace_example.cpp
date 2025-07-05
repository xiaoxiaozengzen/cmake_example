#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

#include <iostream>

#define MAX_STACK_FRAMES 100

void print_backtrace() {
    void* stack[MAX_STACK_FRAMES];

    /**
     * @brief 获取当前线程的调用栈信息
     * @param stack 存储调用栈地址的数组
     * @param MAX_STACK_FRAMES 数组的最大大小
     * @return 返回实际获取的栈帧数量，不会超过 MAX_STACK_FRAMES
     */
    int frames = backtrace(stack, MAX_STACK_FRAMES);

    /**
     * @brief 将调用栈地址转换为符号名称
     * @param stack 存储调用栈地址的数组
     * @param frames 实际获取的栈帧数量
     * @return 返回一个字符串数组，每个元素是对应栈帧的符号名称
     * @note 需要包含 <execinfo.h> 头文件，并链接时使用 -rdynamic 选项
     *       以确保符号信息能够正确解析。
     *       注意：在某些系统上，可能需要链接 libexecinfo 库
     *       来支持 backtrace_symbols 函数。
     * @note 调用free(symbols) 释放内存是必要的，
     *       因为 backtrace_symbols 返回的内存是动态分配的。
     */
    char** symbols = backtrace_symbols(stack, frames);

    std::cout << "Backtrace (most recent call first):" << std::endl;
    for (int i = 0; i < frames; ++i) {
        std::cout << "[" << i << "]: " << symbols[i] << std::endl;
    }

    // 释放 backtrace_symbols 分配的内存
    free(symbols);

    /**
     * @brief 将调用栈信息输出到标准错误输出
     * @param stack 存储调用栈地址的数组
     * @param frames 实际获取的栈帧数量
     * @param STDERR_FILENO 标准错误输出文件描述符
     * 
     * @note 改函数不会动态分配内存，因此不需要手动释放。
     */
    backtrace_symbols_fd(stack, frames, STDERR_FILENO);
}

void signal_handler(int signal) {
    std::cerr << "Received signal: " << signal << std::endl;
    print_backtrace();
    exit(signal);
}

void fun1() {
    std::cout << "In function fun1()" << std::endl;
    int * a = nullptr; // 触发段错误
    *a = 42; // 这里会导致段错误
}

void fun2() {
    std::cout << "In function fun2()" << std::endl;
    fun1(); // 调用 fun1，触发段错误
}

int main() {
    // 注册信号处理函数
    signal(SIGSEGV, signal_handler); // 捕获段错误信号
    signal(SIGABRT, signal_handler); // 捕获中止信号

    std::cout << "Starting backtrace example..." << std::endl;

    // 调用 fun2，触发段错误
    fun2();

    return 0; // 正常结束程序
}