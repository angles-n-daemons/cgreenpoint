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

void testClassesNested() {
  runTest(" \
    class Pie {} \
    var apple = Pie(); \
    apple.filling = \"apples\"; \
    apple.nested = Pie(); \
    apple.nested.filling = \"blueberries\"; \
    print apple.nested.filling; \
          ",
          "blueberries");
}

void testClassPropertyArithmetic() {
  runTest(" \
class Pair {} \
 \
var pair = Pair(); \
pair.first = 1; \
pair.second = 2; \
print pair.first + pair.second; // 3. \
  ",
          "3");
}

void testClass() {
  printf("testClass starting\n");
  testClassSimple();
  testClassFields();
  testClassesNested();
  testClassPropertyArithmetic();
  printf("testClass completed\n");
}
