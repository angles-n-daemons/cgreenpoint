#include <stdio.h>

#include "test_common.h"

void testStrings() {
    printf("Strings tests starting\n");
    runTest("\"ello muppet\"", "\"ello muppet\"");
    runTest("\"ello muppet\" == \"ello muppet\"", "true");
    runTest("\"ello muppet\" == \"chello poppet\"", "false");
    runTest("\"st\" + \"ri\" + \"ng\"", "\"string\"");
    printf("Strings tests completed\n");
}
