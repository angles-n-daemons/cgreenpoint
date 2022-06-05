#include <stdio.h>

#include "vm/test_chunk.h"
#include "vm/test_vm.h"
#include "compiler/test_scanner.h"
#include "compiler/test_compiler.h"
#include "test_strings.h"

void runTests() {
	testChunk();
	testVM();
	testScanner();
	testCompiler();
  testStrings();
	printf("all tests pass\n");
}
