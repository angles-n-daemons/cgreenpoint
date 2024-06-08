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

void testCoffeeMeetsBagel() {
  runTest("\
    fun makeClosure(value) { \
      fun closure() { \
        print value; \
      } \
      return closure; \
    } \
    var doughnut = makeClosure(\"doughnut\"); \
    var bagel = makeClosure(\"bagel\"); \
    doughnut(); \
    bagel();",
          "doughnut\nbagel");
}

void testClosure() {
  printf("testClosure starting\n");
  testClosureBasic();
  testCoffeeMeetsBagel();
  printf("testClosure completed\n");
}
