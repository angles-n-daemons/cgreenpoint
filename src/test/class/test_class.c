#include <stdio.h>

#include "../test_common.h"

void testClassSimple() {
  runTest(" \
    class Brioche {} \
    print Brioche; \
    print Brioche(); \
  ",
          "Brioche\nBrioche instance");
}

void testClass() {
  printf("testClass starting\n");
  testClassSimple();
  printf("testClass completed\n");
}
