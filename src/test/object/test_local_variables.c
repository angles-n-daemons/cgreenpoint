#include <stdio.h>

#include "../test_common.h"


void testLocalVariablesBasic() {
    runTest("{ var a = 5; { var b = 2; print a + b; } }", "7");
}

void testLocalVariablesMultiple() {
    runTest("{ var a = 5; var b = 2; var c = 1; print b; }", "2");
}


void testMultipleLevelsLocalVariables() {
    runTest("var a = 5; { var a = 3; {var a = 1; print a; }}", "1");
}


void testLocalVariables() {
    printf("testLocalVariables starting\n");
    testLocalVariablesBasic();
    testLocalVariablesMultiple();
    testMultipleLevelsLocalVariables();
    printf("testLocalVariables completed\n");
}
