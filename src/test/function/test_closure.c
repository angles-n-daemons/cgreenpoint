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

void testNoGlobal() {
  runTest("\
   fun outer() { \
     var x = \"closed\"; \
     fun inner() { \
       print x; \
     } \
     inner(); \
    } \
   outer();",
          "closed");
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

void testClosedUpvalues() {
  runTest("\
    var globalSet; \
    var globalGet; \
     \
    fun main() { \
      var a = \"initial\"; \
     \
      fun set() { a = \"updated\"; } \
      fun get() { print a; } \
     \
      globalSet = set; \
      globalGet = get; \
    } \
     \
    main(); \
    globalSet(); \
    globalGet();",
          "doughnut\nbagel");
}

void testClosure() {
  printf("testClosure starting\n");
  testClosureBasic();
  testNoGlobal();
  testCoffeeMeetsBagel();
  testClosedUpvalues();
  printf("testClosure completed\n");
}
