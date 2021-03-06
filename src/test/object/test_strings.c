#include <stdlib.h>
#include <stdio.h>

#include "../test_common.h"
#include "../../main/object/object.h"

void testHash(char* s, int length, uint32_t expected) {
    ObjString* string = copyString(s, length);
    if (string->hash != expected) {
        printf("failed testHash: hashing %s expected %d but got %d\n", s, expected, string->hash);
        exit(1);
    }
}

void testStrings() {
    printf("testStrings starting\n");
    runTest("\"ello muppet\"", "\"ello muppet\"");
    runTest("\"ello muppet\" == \"ello muppet\"", "true");
    runTest("\"ello muppet\" == \"chello poppet\"", "false");
    runTest("\"st\" + \"ri\" + \"ng\"", "\"string\"");

    testHash("test", 4, -1345293851);
    testHash("banana ", 7, -502071984);
    testHash("banana", 7, -1038955792);
    printf("testStrings completed\n");
}
