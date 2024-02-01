#include <stdio.h>

#include "../test_common.h"

void testSimpleWhile() {
    runTest("\n \
        var i = 0;\n \
        while (i < 10) {\n \
            i = i + 1;\n \
        }\n \
        print i;\n \
    ", "10");

    runTest("\n \
        var i = 0;\n \
        while (i > 10) {\n \
            i = i + 1;\n \
        }\n \
        print i;\n \
    ", "0");
}

void testWhileNoParens() {
    runTest("\n \
        var i = 0;\n \
        while i < 10 {\n \
            i = i + 1;\n \
        }\n \
        print i;\n \
    ", "Expect '(' after 'while'.");
}

void testWhileMissingRightParen() {
    runTest("\n \
        var i = 0;\n \
        while (i < 10 {\n \
            i = i + 1;\n \
        }\n \
        print i;\n \
    ", "Expect ')' after expression.");
}

void testWhile() {
    printf("testWhile starting\n");
    testSimpleWhile();
    testWhileNoParens();
    testWhileMissingRightParen();
    printf("testWhile completed\n\n");
}
