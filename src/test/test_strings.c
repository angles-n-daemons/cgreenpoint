#include <stdio.h>

#include "test_common.h"

void testStrings() {
    printf("Strings tests starting\n");
    runTest("\"ello muppet\"", "\"ello muppet\"");
    runTest("\"ello muppet\" == \"ello muppet\"", "true");
    runTest("\"ello muppet\" == \"chello poppet\"", "false");
    printf("Strings tests completed\n");
}
