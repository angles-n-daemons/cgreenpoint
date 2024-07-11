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

void testClassFields() {
  runTest(" \
    class Pie {} \
    var apple = Pie(); \
    apple.filling = \"apples\"; \
    print apple.filling; \
  ",
          "apples");
}

void testClass() {
  printf("testClass starting\n");
  testClassSimple();
  testClassFields();
  printf("testClass completed\n");
}
