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

void testClosuresAsObjects() {
  runTest(" \
    fun vector(x, y) {\
        fun handler(f) {\
            return f(x, y);\
        }\
        return handler;\
    }\
\
    fun getX(v) {\
        fun getIt(x, y) {\
            return x;\
        }\
        return v(getIt);\
    }\
\
    fun getY(v) {\
        fun getIt(x, y) {\
            return y;\
        }\
        return v(getIt);\
    }\
\
    fun add(v1, v2) {\
        var x = getX(v1) + getX(v2);\
        var y = getY(v1) + getY(v2);\
        return vector(x, y);\
    }\
\
    var v1 = vector(1, 2);\
    var v2 = vector(3, 4);\
    var v3 = add(v1, v2);\
    print getX(v3);\
    print getY(v3);\
          ",
          "4\n6");
}

void testClosure() {
  printf("testClosure starting\n");
  testClosureBasic();
  testNoGlobal();
  testCoffeeMeetsBagel();
  testClosedUpvalues();
  testClosuresAsObjects();
  printf("testClosure completed\n");
}
