#include "test_vm.h"
#include "../../vm/chunk.h"
#include "../../vm/vm.h"

void testVMBasic() {
	// setup
	initVM();
	Chunk chunk;
	initChunk(&chunk);

	writeConstant(&chunk, 1.2, 1);
	writeChunk(&chunk, OP_RETURN, 3);
	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMConstant16() {
	// setup
	initVM();
	Chunk chunk;
	initChunk(&chunk);

	for(int i=0; i < 100; i++) {
		Value value = (double)i;
		writeConstant(&chunk, value, i);
	}

	writeChunk(&chunk, OP_RETURN, 300);
	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMNegate() {
	initVM();

	Chunk chunk;
	initChunk(&chunk);
	
	writeConstant(&chunk, 13.37, 2);
	writeChunk(&chunk, OP_NEGATE, 2);
	writeChunk(&chunk, OP_RETURN, 4);

	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMAdd() {
	printf("test_vm: testing addition\n");
	initVM();

	Chunk chunk;
	initChunk(&chunk);
	
	writeConstant(&chunk, 1.0, 2);
	writeConstant(&chunk, 2.0, 2);
	writeChunk(&chunk, OP_ADD, 2);
	writeChunk(&chunk, OP_RETURN, 4);

	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMSubtract() {
	printf("test_vm: testing subtraction\n");
	initVM();

	Chunk chunk;
	initChunk(&chunk);
	
	writeConstant(&chunk, 1.0, 2);
	writeConstant(&chunk, 2.0, 2);
	writeChunk(&chunk, OP_SUBTRACT, 2);
	writeChunk(&chunk, OP_RETURN, 4);

	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMDivide() {
	printf("test_vm: testing division\n");
	initVM();

	Chunk chunk;
	initChunk(&chunk);
	
	writeConstant(&chunk, 1.0, 2);
	writeConstant(&chunk, 2.0, 2);
	writeChunk(&chunk, OP_DIVIDE, 2);
	writeChunk(&chunk, OP_RETURN, 4);

	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVMMultiply() {
	printf("test_vm: testing multiplication\n");
	initVM();

	Chunk chunk;
	initChunk(&chunk);
	
	writeConstant(&chunk, 1.0, 2);
	writeConstant(&chunk, 2.0, 2);
	writeChunk(&chunk, OP_MULTIPLY, 2);
	writeChunk(&chunk, OP_RETURN, 4);

	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVM() {
	//testVMBasic();
	//testVMConstant16();
	//testVMNegate();
	testVMAdd();
	testVMSubtract();
	testVMDivide();
	testVMMultiply();
	printf("testVM ran successfully\n");
}
