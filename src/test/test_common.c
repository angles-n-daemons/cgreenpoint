#include <stdlib.h>

#include "../main/common.h"
#include "../main/vm/vm.h"

void runTest(const char* test, const char* expected) {
    printf("testing greenpoint program '%s'\n", test);
    initVM();
    printf("======= PROGRAM OUTPUT START =======");
    interpret(test);
    printf("======= PROGRAM OUTPUT END    =======");
    freeVM();
    printf("expected %s\n", expected);
    printf("end test %s\n\n", test);
}
