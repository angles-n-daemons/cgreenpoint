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

void testClassMethodSimple() {
  runTest(" \
    class Brunch { \
      bacon() { \
        print \"bacon\"; \
      } \
      eggs() { \
        print \"eggs\"; \
      } \
    } \
    var brunch = Brunch(); \
    brunch.bacon(); \
    brunch.eggs(); \
  ",
          "bacon\neggs");
}

void testClassMethodWithParams() {
  runTest(" \
    class Scone { \
      topping(first, second) { \
        print \"scone with \" + first + \" and \" + second; \
      } \
    } \
     \
    var scone = Scone(); \
    scone.topping(\"berries\", \"cream\"); \
        ",
          "scone with berries and cream");
}

void testClassMethodBinding() {
  runTest(" \
    class Person { \
      sayName() { \
        print this.name; \
      } \
    } \
     \
    var jane = Person(); \
    jane.name = \"Jane\"; \
     \
    var method = jane.sayName; \
    method(); \
  ",
          "Jane");
}

void testClassMethodThisReceiver() {
  runTest(" \
    class Nested { \
      method() { \
        fun function() { \
          print this; \
        } \
     \
        function(); \
      } \
    } \
     \
    Nested().method(); \
            ",
          "Nested instance");
}

void testClass() {
  printf("testClass starting\n");
  testClassSimple();
  testClassFields();
  testClassesNested();
  testClassPropertyArithmetic();
  testClassMethodSimple();
  testClassMethodWithParams();
  testClassMethodBinding();
  testClassMethodThisReceiver();
  printf("testClass completed\n");
}
