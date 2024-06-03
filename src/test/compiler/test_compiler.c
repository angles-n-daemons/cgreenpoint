#include <stdio.h>

#include "../test_common.h"

void testCompiler() {
  printf("testCompiler starting\n");

  runTest("print 5 + 4;", "9");
  runTest("print 5 - 3 - 2;", "0");
  runTest("print (4 + 3) * 3;", "21");
  runTest("print 4 + 3 * 3;", "13");
  runTest("print 4 + (3 * 3);", "13");
  runTest("print 2 * 8 - 6 / 2;", "13");
  runTest("print (-1 + 2) * 3 - -4;", "7");

  printf("testCompiler completed\n");
}
