#include <stdio.h>

#include "../test_common.h"


void testSimpleVariables() {
    runTest("var a = 5; a = 4; print a;", "4");
}

void testInvalidAssignment() {
    runTest("var a = 4; b = 3; a * b = 5;", "Invalid assignment target.");
}

void testVariables() {
    printf("testTable starting\n");
    testSimpleVariables();
    testInvalidAssignment();
    printf("testTable completed\n");
}
