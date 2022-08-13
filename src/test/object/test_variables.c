#include <stdio.h>

#include "../test_common.h"


void testSimpleVariables() {
    runTest("var a = 5;", "5");    
}

void testVariables() {
    printf("testTable starting\n");
    testSimpleVariables();
    printf("testTable completed\n");
}
