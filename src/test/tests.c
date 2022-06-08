#include <stdio.h>

#include "vm/test_chunk.h"
#include "vm/test_vm.h"
#include "compiler/test_scanner.h"
#include "compiler/test_compiler.h"
#include "object/test_strings.h"
#include "object/test_table.h"

void runTests() {
	printf("starting tests\n");
	testChunk();
	testVM();
	testScanner();
	testCompiler();
  testStrings();
	testTable();
	printf("all tests pass\n");
}
