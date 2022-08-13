#include <stdio.h>

#include "../test_common.h"


void testSimpleVariables() {
    runTest("var a = 5; a = 4; print a;", "4");
}

void testVariables() {
    printf("testTable starting\n");
    testSimpleVariables();
    printf("testTable completed\n");
}
