#include <stdio.h>

#include "vm/test_chunk.h"
#include "vm/test_vm.h"
#include "compiler/test_scanner.h"
#include "compiler/test_compiler.h"
#include "object/test_strings.h"
#include "object/test_table.h"
#include "object/test_variables.h"
#include "object/test_local_variables.h"
#include "controlflow/test_ifelse.h"
#include "controlflow/test_andor.h"
#include "controlflow/test_while.h"

void runTests() {
    printf("starting tests\n");
    testChunk();
    testVM();
    testScanner();
    testCompiler();
    testStrings();
    testTable();
    testVariables();
    testLocalVariables();
    testIfElse();
    testAndOr();
    testWhile();
    printf("all tests pass\n");
}
