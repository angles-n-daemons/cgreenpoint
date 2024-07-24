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
    }",
          "dunking\nglazing");
}

void testInheritance() {
  printf("testInheritance starting\n");
  testInheritanceBasic();
  printf("testInheritance completed\n");
}
