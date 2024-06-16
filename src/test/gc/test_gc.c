#include <stdio.h>

#include "../test_common.h"

void testGCBasic() { runTest("", ""); }

void testGC() {
  printf("testGC starting\n");
  testGCBasic();
  printf("testGC completed\n");
}
