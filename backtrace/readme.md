# Overvirw

使用backtrace的例子

# 直接使用g++进行编译

```bash
# 编译
g++ backtrace_example.cpp -o example -g -rdynamic

# 执行
./example

# 打印如下
[0]: ./example(_Z15print_backtracev+0x32) [0x55dff45e331b]
[1]: ./example(_Z15signale_handleri+0x2a) [0x55dff45e3418]
[2]: /lib/x86_64-linux-gnu/libc.so.6(+0x43090) [0x7fd391855090]
[3]: ./example(_Z4fun1v+0x40) [0x55dff45e3462]
[4]: ./example(_Z4fun2v+0x35) [0x55dff45e34a0]
[5]: ./example(_Z4fun3v+0x35) [0x55dff45e34d8]
[6]: ./example(main+0x5c) [0x55dff45e3537]
[7]: /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3) [0x7fd391836083]
[8]: ./example(_start+0x2e) [0x55dff45e322e]
```

## 使用cmake