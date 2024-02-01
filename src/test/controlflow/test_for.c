#include <stdio.h>

#include "../test_common.h"

void testSimpleFor() {
    runTest("\n \
        for (var i = 0; i < 5; i++) {\n \
            print i;\n \
        }\n \
    ", "0\n1\n2\n3\n4\n");
}

void testForMissingInitializer() {
    runTest("\n \
        var i = 0;\n \
        for (; i < 5; i++) {\n \
            print i;\n \
        }\n \
    ", "0\n1\n2\n3\n4\n");
}

void testForImmediatelyExits() {
    runTest("\n \
        var i = 0;\n \
        for (; i > 5; i++) {\n \
            print i;\n \
        }\n \
    ", "<NOTHING>");
}

void testForGoofyCase() {
    runTest("\n \
        var i = 0;\n \
        for (; i < 5; i++) {\n \
            i = i+1;\n \
            print i;\n \
        }\n \
    ", "<NOTHING>");
}

void testFor() {
    printf("testFor starting\n");
    testSimpleFor();
    testForMissingInitializer();
    testForImmediatelyExits();
    testForGoofyCase();
    printf("testFor completed\n\n");
}
