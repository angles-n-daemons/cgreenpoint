#include <stdlib.h>

#include "../common.h"
#include "../vm/vm.h"

void runTest(const char* test, const char* expected) {
    printf("testing greenpoint program '%s'\n", test);
    initVM();
    interpret(test);
    freeVM();
    printf("expected %s\n", expected);
    printf("end test %s\n\n", test);
}
