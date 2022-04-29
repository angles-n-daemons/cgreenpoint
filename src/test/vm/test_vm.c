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

	for(int i=0; i < 270; i++) {
		Value value = (double)i;
		writeConstant(&chunk, value, i);
	}

	writeChunk(&chunk, OP_RETURN, 300);
	interpret(&chunk);

	// teardown
	freeChunk(&chunk);
	freeVM();
}

void testVM() {
	testVMBasic();
	testVMConstant16();
	printf("testVM ran successfully\n");
}
