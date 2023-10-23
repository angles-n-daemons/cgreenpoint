#include <stdio.h>

#include "../test_common.h"


void testLocalVariablesBasic() {
    runTest("{ var a = 5; { var b = 2; print a + b; } }", "7");
}

void testLocalVariables() {
    printf("testLocalVariables starting\n");
    testLocalVariablesBasic();
    printf("testLocalVariables completed\n");
}
