#include <stdlib.h>

#include "../main/common.h"
#include "../main/vm/vm.h"

void runTest(const char *test, const char *expected) {
  printf("testing greenpoint program '%s'\n", test);
  initVM();
  printf("======= PROGRAM OUTPUT START =======\n");
  interpret(test);
  printf("======= PROGRAM OUTPUT END   =======\n");
  freeVM();
  printf("expected %s\n", expected);
  printf("end test\n\n");
}
