#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "../../main/vm/chunk.h"
#include "../../main/vm/vm.h"

#include "test_vm.h"

void testVMBasic() {
    // setup
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    writeConstant(&chunk, NUMBER_VAL(1.2), 1);
    writeChunk(&chunk, OP_RETURN, 3);
    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMConstant16() {
    // setup
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    for(int i=0; i < 300; i++) {
        Value value = NUMBER_VAL((double)i);
        writeConstant(&chunk, value, i);
    }

    writeChunk(&chunk, OP_RETURN, 300);
    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMNegate() {
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(13.37), 2);
    writeChunk(&chunk, OP_NEGATE, 2);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMAdd() {
    printf("test_vm: testing addition\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1.0), 2);
    writeConstant(&chunk, NUMBER_VAL(2.0), 2);
    writeChunk(&chunk, OP_ADD, 2);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMSubtract() {
    printf("test_vm: testing subtraction\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1.0), 2);
    writeConstant(&chunk, NUMBER_VAL(2.0), 2);
    writeChunk(&chunk, OP_SUBTRACT, 2);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMDivide() {
    printf("test_vm: testing division\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1.0), 2);
    writeConstant(&chunk, NUMBER_VAL(2.0), 2);
    writeChunk(&chunk, OP_DIVIDE, 2);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testVMMultiply() {
    printf("test_vm: testing multiplication\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1.0), 2);
    writeConstant(&chunk, NUMBER_VAL(2.0), 2);
    writeChunk(&chunk, OP_MULTIPLY, 2);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}


void testVMComplex() {
    printf("test_vm: testing complex expression\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1.2), 2);
    writeConstant(&chunk, NUMBER_VAL(3.4), 2);
    writeChunk(&chunk, OP_ADD, 2);
    writeConstant(&chunk, NUMBER_VAL(5.6), 2);
    writeChunk(&chunk, OP_DIVIDE, 4);
    writeChunk(&chunk, OP_NEGATE, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge1_1() {
    printf("test_vm: testing challenge 1_1\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1), 2);
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeChunk(&chunk, OP_MULTIPLY, 2);
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeChunk(&chunk, OP_ADD, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge1_2() {
    printf("test_vm: testing challenge 1_2\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeChunk(&chunk, OP_MULTIPLY, 2);
    writeConstant(&chunk, NUMBER_VAL(1), 2);
    writeChunk(&chunk, OP_ADD, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge1_3() {
    printf("test_vm: testing challenge 1_3\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeChunk(&chunk, OP_SUBTRACT, 2);
    writeConstant(&chunk, NUMBER_VAL(1), 2);
    writeChunk(&chunk, OP_SUBTRACT, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge1_4() {
    printf("test_vm: testing challenge 1_4\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(1), 2);
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeChunk(&chunk, OP_MULTIPLY, 2);
    writeChunk(&chunk, OP_ADD, 2);
    writeConstant(&chunk, NUMBER_VAL(4), 2);
    writeConstant(&chunk, NUMBER_VAL(5), 2);
    writeChunk(&chunk, OP_NEGATE, 4);
    writeChunk(&chunk, OP_DIVIDE, 4);
    writeChunk(&chunk, OP_SUBTRACT, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge2_1() {
    printf("test_vm: testing challenge 2_1\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(4), 2);
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeConstant(&chunk, NUMBER_VAL(0), 2);
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeChunk(&chunk, OP_SUBTRACT, 4);
    writeChunk(&chunk, OP_MULTIPLY, 4);
    writeChunk(&chunk, OP_SUBTRACT, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenge2_2() {
    printf("test_vm: testing challenge 2_2\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(4), 2);
    writeConstant(&chunk, NUMBER_VAL(3), 2);
    writeConstant(&chunk, NUMBER_VAL(2), 2);
    writeChunk(&chunk, OP_NEGATE, 4);
    writeChunk(&chunk, OP_MULTIPLY, 4);
    writeChunk(&chunk, OP_NEGATE, 4);
    writeChunk(&chunk, OP_ADD, 4);
    writeChunk(&chunk, OP_RETURN, 4);

    interpretChunk(&chunk);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

void testChallenge4() {
    // averages 600 to do 100000 for push pop impl, 300s to do for in place change
  struct timespec start, end;
    printf("test_vm: testing challenge 2_2\n");
    initVM();

    Chunk chunk;
    initChunk(&chunk);
    
    writeConstant(&chunk, NUMBER_VAL(4), 2);
    writeChunk(&chunk, OP_NEGATE, 4);
    writeChunk(&chunk, OP_RETURN, 4);

  clock_gettime(CLOCK_MONOTONIC, &start);
    interpretChunk(&chunk);
  clock_gettime(CLOCK_MONOTONIC, &end);
    uint64_t timeElapsed = timespecDiff(&end, &start);
    printf("%" PRIu64 "\n", timeElapsed);

    // teardown
    freeChunk(&chunk);
    freeVM();
}

void testChallenges() {
    testChallenge1_1();
    testChallenge1_2();
    testChallenge1_3();
    testChallenge1_4();
    testChallenge2_1();
    testChallenge2_2();
    testChallenge4();
}

void testVM() {
    printf("testVM starting\n");
    testVMBasic();
    testVMConstant16();
    testVMNegate();
    testVMAdd();
    testVMSubtract();
    testVMDivide();
    testVMMultiply();
    testVMComplex();
    testChallenges();
    printf("testVM completed\n");
}
