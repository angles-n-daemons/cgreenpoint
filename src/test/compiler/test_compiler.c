#include <stdlib.h>

#include "../../common.h"
#include "../../vm/vm.h"

void runTest(const char* test, const char* expected) {
    printf("compiler testing %s\n", test);
    initVM();
    interpret(test);
    freeVM();
    printf("expected %s", expected);
}

void testCompiler() {
    runTest("5 + 4", "9");
    runTest("5 - 3 - 2", "0");
    runTest("(4 + 3) * 3", "21");
    runTest("4 + 3 * 3", "13");
    runTest("4 + (3 * 3)", "13");
    runTest("2 * 8 - 6 / 2", "13");
    runTest("(-1 + 2) * 3 - -4", "11");
    
    printf("Compiler tests completed\n");
}
