#include <stdlib.h>
#include <stdio.h>

#include "../test_common.h"

void testFunctionBasic() {
    runTest("\
    fun first() {\
        var a = 1;\
        second();\
        var b = 2;\
        print a + b;\
        second();\
    }\
    \
    fun second() {\
        var c = 3;\
        var d = 4;\
        print c + d;\
    }\
    \
    first()", "\n7\n3\n7");
}

void testFunction() {
    printf("testFunction starting\n");
    testFunctionBasic();
    printf("testFunction completed\n");
}
