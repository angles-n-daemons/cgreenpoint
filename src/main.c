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
  // InterpretResult result = interpret(source);
  free(source);

  // if (result == INTERPRET_COMPILE_ERROR) exit(65);
  // if (result == INTERPRET_RUNTIME_ERROR) exit(65);
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

int main(int argc, const char *argv[]) {
  if (argc > 1 && strcmp("test", argv[1]) == 0) {
    runTests();
  } else {
    run(argc, argv);
  }
  return 0;
}
