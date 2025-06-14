#include "client/linux/handler/exception_handler.h"

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
void* context, bool succeeded) {
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}

void CoreFun(int * a) {
  int b = *a;
}

int main(int argc, char* argv[]) {
  google_breakpad::MinidumpDescriptor descriptor("/tmp");
  google_breakpad::ExceptionHandler eh(descriptor, NULL, dumpCallback, NULL, true, -1);
  

  int * a = nullptr;
  CoreFun(a); // This will cause a segmentation fault (null pointer dereference)
  return 0;
}
