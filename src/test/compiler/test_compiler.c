#include <stdlib.h>

#include "../../common.h"
#include "../../vm/vm.h"

void runTest(const char* s) {
    printf("compiler testing %s\n", s);
    initVM();
    interpret(s);
}

void testCompiler() {
    runTest("5 + 4");
    runTest("5 - 3 - 2");
    runTest("(4 + 3) * 3");
    runTest("4 + 3 * 3");
    runTest("4 + (3 * 3)");
    runTest("2 * 8 - 6 / 2");
    
    printf("Compiler tests completed\n");
}
