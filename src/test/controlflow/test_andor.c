#include <stdio.h>

#include "../test_common.h"

void testSimpleAnd() {
    runTest("print false and false;", "false");
    runTest("print true and false;", "false");
    runTest("print false and true;", "false");
    runTest("print true and true;", "true");
}

void testSimpleOr() {
    runTest("print false or false;", "false");
    runTest("print true or false;", "true");
    runTest("print false or true;", "true");
    runTest("print true or true;", "true");
}

void testCombinedAndOr() {
    runTest("print false or true and true;", "true");
    runTest("print false or true and false;", "false");
}

void testAndOrWithExtraSteps() {
    runTest("var a = 5; var b = a > 3; print b;", "true");
}

void testAndOr() {
    printf("testAndOr starting\n");
    testSimpleAnd();
    testSimpleOr();
    testCombinedAndOr();
    testAndOrWithExtraSteps();
    printf("testAndOr completed\n");
}
