#include <stdlib.h>

#include "../main/common.h"
#include "../main/vm/vm.h"

void runTest(const char *test, const char *expected) {
  printf("testing greenpoint program '%s'\n", test);
  initVM();
  printf("======= PROGRAM OUTPUT  =======\n");
  interpret(test);
  printf("======= EXPECTED OUTPUT =======\n");
  printf("%s\n", expected);
  printf("======= END             =======\n");
  freeVM();
  printf("end test\n\n");
}
