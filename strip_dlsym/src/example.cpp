#include <dlfcn.h>
#include <cstdlib>

#include <iostream>

#include "example.hpp"

void example_function() {
    const char* lib_path = std::getenv("MY_LIB_PATH");
    if(lib_path == nullptr) {
        std::cerr << "MY_LIB_PATH is not set" << std::endl;
        return;
    }

    void* handle = dlopen(lib_path, RTLD_LAZY);
    if (handle == nullptr) {
        std::cerr << "Failed to open libmy_library.so: " << dlerror() << std::endl;
        return;
    }

    void (*fun)() = reinterpret_cast<void (*)()>(dlsym(handle, "_Z19my_library_functionv"));
    if (fun == nullptr) {
        std::cerr << "Failed to find my_library_function: " << dlerror() << std::endl;
        return;
    }

    fun();
    dlclose(handle);
}
