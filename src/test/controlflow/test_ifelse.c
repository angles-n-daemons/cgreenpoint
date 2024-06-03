#include <stdio.h>

#include "../test_common.h"

void testIfElseStatement() {
  printf("testing if else statement\n");
  // test just the if statement
  runTest("if (true) print \"succeeded\";", "succeeded");

  // test entering if block but not else block
  runTest("if (true) print \"succeeded\"; else print \"failed\";", "succeeded");

  // test entering else block
  runTest("if (false) print \"failed\"; else print \"succeeded\";",
          "succeeded");
}

void testIfElseNested() {
  printf("testing nested if else statement\n");
  runTest(" \n \
        if (true) { \n \
            if (true) { \n \
                print \"succeeded\"; \n \
            } else { \n \
                print \"failed if > else\"; \n \
            } \n \
        } else { \n \
            if (true) { \n \
                print \"failed else > if\"; \n \
            } else { \n \
                print \"failed else > else\"; \n \
            } \n \
        } \n \
    ",
          "succeeded");
}

void testIfComplexExpression() {
  printf("testing if else with complex expression\n");

  runTest(" \n \
        var a = 5; \n \
        var b = 3; \n \
        if (10 < (a * b)) { \n \
            print \"succeeded\"; \n \
        } else { \n \
            print \"failed\"; \n \
        } \
    ",
          "succeeded");
}

void testIfElse() {
  printf("testIfElse starting\n");
  testIfElseStatement();
  testIfElseNested();
  testIfComplexExpression();
  printf("testIfElse completed\n\n\n");
}
