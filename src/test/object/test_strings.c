#include <stdlib.h>
#include <stdio.h>

#include "../test_common.h"
#include "../../main/object/object.h"

void testHash(char* s, int length, uint32_t expected) {
    printf("testing hash %s %d %d\n", s, length, expected);
    ObjString* string = copyString(s, length);
    if (string->hash != expected) {
        printf("failed testHash: hashing %s expected %d but got %d\n", s, expected, string->hash);
        exit(1);
    }
}

void testStrings() {
    printf("testStrings starting\n");
    runTest("print \"ello muppet\";", "\"ello muppet\"");
    runTest("print \"ello muppet\" == \"ello muppet\";", "true");
    runTest("print \"ello muppet\" == \"chello poppet\";", "false");
    runTest("print \"st\" + \"ri\" + \"ng\";", "\"string\"");

    testHash("test", 4, -1345293851);
    testHash("banana ", 7, -502071984);
    testHash("banana", 7, -1038955792);
    printf("testStrings completed\n");
}
