#include <stdio.h>

#include "class/test_class.h"
#include "class/test_inheritance.h"
#include "compiler/test_compiler.h"
#include "compiler/test_scanner.h"
#include "controlflow/test_andor.h"
#include "controlflow/test_for.h"
#include "controlflow/test_ifelse.h"
#include "controlflow/test_while.h"
#include "function/test_closure.h"
#include "function/test_function.h"
#include "gc/test_gc.h"
#include "object/test_local_variables.h"
#include "object/test_strings.h"
#include "object/test_table.h"
#include "object/test_variables.h"
#include "vm/test_chunk.h"

void runTests() {
  printf("starting tests\n");
  testChunk();
  testScanner();
  testCompiler();
  testStrings();
  testTable();
  testVariables();
  testLocalVariables();
  testIfElse();
  testAndOr();
  testWhile();
  testFor();
  testFunction();
  testClosure();
  testGC();
  testClass();
  testInheritance();
  printf("all tests pass\n");
}
