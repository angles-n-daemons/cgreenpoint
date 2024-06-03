#include <stdio.h>
#include <stdlib.h>

#include "../test_common.h"

void testFunctionBasic() {
  runTest("\
   fun first() {\
       var a = 1;\
       second();\
       print a;\
       var b = 2;\
       second();\
       print a + b;\
   }\
   \
   fun second() {\
       var c = 3;\
       var d = 4;\
       print c + d;\
   }\
   \
   first()",
          "\n7\n1\n3\n7");
}

void testDeclareFunction() {
  runTest("\
    fun areWeHavingItYet(a, b) { \
        print \"Yes we are!\";\
    } \
    print areWeHavingItYet;",
          "<fn areWeHavingItYet>");
}

void testFunctionWithParams() {
  runTest("\
   fun sum(a, b, c) { \
       return a + b + c; \
   }\
   \
   print 4 + sum(a, b, c);",
          "22");
}

void testCallUncallable() {
  runTest("\
   var notafunction = 123; \
   notafunction();",
          "Can only call functions and classes.");
}

void testFunction() {
  printf("testFunction starting\n");
  testFunctionBasic();
  testDeclareFunction();
  testFunctionWithParams();
  printf("testFunction completed\n");
}
