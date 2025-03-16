#include "example.hpp"

void MyTest() {
    std::cout << "Hello from MyTest!" << std::endl;

    // 初始化 Python 解释器
    Py_Initialize();

    // 执行简单的 Python 代码
    PyRun_SimpleString("print('Hello from Python!')");

    // 终止 Python 解释器
    Py_Finalize();
}