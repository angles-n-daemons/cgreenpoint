#include "main/common.h"
#include "main/vm/chunk.h"
#include "main/vm/debug.h"
#include "main/vm/vm.h"
#include "test/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void repl() {
  char line[1024];
  printf("Hello from beautiful Brooklyn, NY!\n");
  printf("Greenpoint Interpreter: v0.0.0\n");
  for (;;) {
    printf("» ");

    if (!fgets(line, sizeof(line), stdin)) {
      printf("\n");
      break;
    }

    interpret(line);
  }
}

static char *readFile(const char *path) {
  FILE *file = fopen(path, "rb");
  if (file == NULL) {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }

  fseek(file, 0L, SEEK_END);
  size_t fileSize = ftell(file);
  rewind(file);

  char *buffer = (char *)malloc(fileSize + 1);
  if (buffer == NULL) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }

  size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
  if (bytesRead < fileSize) {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }
  buffer[bytesRead] = '\0';

  fclose(file);
  return buffer;
}

static void runFile(const char *path) {
  char *source = readFile(path);
  InterpretResult result = interpret(source);
  free(source);

  if (result == INTERPRET_COMPILE_ERROR)
    exit(65);
  if (result == INTERPRET_RUNTIME_ERROR)
    exit(65);
}

void run(int argc, const char *argv[]) {
  initVM();

  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    fprintf(stderr, "Usage: cgreenpoint [path]\n");
    exit(64);
  }

  freeVM();
}

void printOpCodes() {
  printf("%x OP_CONSTANT\n", OP_CONSTANT);
  printf("%x OP_CONSTANT_16\n", OP_CONSTANT_16);
  printf("%x OP_NIL\n", OP_NIL);
  printf("%x OP_TRUE\n", OP_TRUE);
  printf("%x OP_FALSE\n", OP_FALSE);
  printf("%x OP_POP\n", OP_POP);
  printf("%x OP_GET_LOCAL\n", OP_GET_LOCAL);
  printf("%x OP_SET_LOCAL\n", OP_SET_LOCAL);
  printf("%x OP_GET_UPVALUE\n", OP_GET_UPVALUE);
  printf("%x OP_SET_UPVALUE\n", OP_SET_UPVALUE);
  printf("%x OP_GET_GLOBAL\n", OP_GET_GLOBAL);
  printf("%x OP_SET_GLOBAL\n", OP_SET_GLOBAL);
  printf("%x OP_DEFINE_GLOBAL\n", OP_DEFINE_GLOBAL);
  printf("%x OP_EQUAL\n", OP_EQUAL);
  printf("%x OP_GREATER\n", OP_GREATER);
  printf("%x OP_LESS\n", OP_LESS);
  printf("%x OP_ADD\n", OP_ADD);
  printf("%x OP_SUBTRACT\n", OP_SUBTRACT);
  printf("%x OP_MULTIPLY\n", OP_MULTIPLY);
  printf("%x OP_DIVIDE\n", OP_DIVIDE);
  printf("%x OP_NOT\n", OP_NOT);
  printf("%x OP_NEGATE\n", OP_NEGATE);
  printf("%x OP_PRINT\n", OP_PRINT);
  printf("%x OP_JUMP\n", OP_JUMP);
  printf("%x OP_JUMP_IF_FALSE\n", OP_JUMP_IF_FALSE);
  printf("%x OP_LOOP\n", OP_LOOP);
  printf("%x OP_CALL\n", OP_CALL);
  printf("%x OP_CLOSURE\n", OP_CLOSURE);
  printf("%x OP_RETURN\n", OP_RETURN);
}

int main(int argc, const char *argv[]) {
  if (argc > 1 && strcmp("test", argv[1]) == 0) {
    runTests();
  } else {
    run(argc, argv);
  }
  return 0;
}
