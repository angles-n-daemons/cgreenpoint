#include <stdlib.h>

#include "../../main/common.h"
#include "../../main/vm/chunk.h"
#include "../../main/vm/debug.h"

void testConstant() {
  Chunk chunk;
  initChunk(&chunk);

  for (int i = 0; i < 5; i++) {
    Value value = NUMBER_VAL((double)i);
    writeConstant(&chunk, value, i);
  }

  disassembleChunk(&chunk, "hello");

  for (int i = 0; i < 5; i++) {
    double expected = (double)i;
    int location = (int)chunk.code[i * 2 + 1];
    double value = AS_NUMBER(chunk.constants.values[location]);
    if (value != expected) {
      printf("failed testConstant: expected %f but got %f\n", expected, value);
      exit(1);
    }
  }

  freeChunk(&chunk);
}

void testConstant16() {
  Chunk chunk;
  initChunk(&chunk);

  for (int i = 0; i < 256; i++) {
    Value value = NUMBER_VAL((double)i);
    writeConstant(&chunk, value, i);
  }

  disassembleChunk(&chunk, "hello");

  // test for 256
  int constant = 256;
  uint8_t firstByte = constant & 0xff;
  uint8_t secondByte = (constant >> 8) & 0xff;

  int derp = 0;
  derp += firstByte;
  derp += (secondByte << 8);
  printf("%d derp\n", derp);

  freeChunk(&chunk);
}

void testChunk() {
  printf("testChunk starting\n");
  testConstant();
  testConstant16();
  printf("testChunk completed\n");
}
