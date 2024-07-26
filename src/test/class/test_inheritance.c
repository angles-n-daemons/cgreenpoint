#include "test_inheritance.h"
#include <stdio.h>

#include "../test_common.h"

void testInheritanceBasic() {
  runTest(" \
    class Doughnut { \
      cook() { \
        print \"dunking\"; \
      } \
    } \
     \
    class Cruller < Doughnut { \
      finish() { \
        print \"glazing\"; \
      } \
    } \
    var breakfast = Cruller(); \
    breakfast.cook(); \
    breakfast.finish();",
          "dunking\nglazing");
}

void testNonClassInheritance() {
  runTest(" \
    var NotClass = \"So not a class\"; \
    class OhNo < NotClass {}",
          "Superclass must be a class.");
}

void testSuperCalls() {
  runTest(" \
  class A { \
    method() { \
      print \"A method\"; \
    } \
  } \
   \
  class B < A { \
    method() { \
      print \"B method\"; \
    } \
   \
    test() { \
      super.method(); \
    } \
  } \
   \
  class C < B {} \
   \
  C().test();",
          "A method");
}

void testInheritance() {
  printf("testInheritance starting\n");
  testInheritanceBasic();
  testNonClassInheritance();
  testSuperCalls();
  printf("testInheritance completed\n");
}
