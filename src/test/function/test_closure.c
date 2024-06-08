#include <stdio.h>

#include "../test_common.h"

void testClosureBasic() {
  runTest("\
   var x = \"global\"; \
   fun outer() { \
     var x = \"outer\"; \
     fun inner() { \
       print x; \
     } \
     inner(); \
    } \
   outer();",
          "outer");
}

void testClosure() {
  printf("testClosure starting\n");
  testClosureBasic();
  printf("testClosure completed\n");
}
