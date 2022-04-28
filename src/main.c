#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;
	initChunk(&chunk);
	int constant = addConstant(&chunk, 1.2);
	int constant2 = addConstant(&chunk, 5.3);

	writeChunk(&chunk, OP_CONSTANT, 1);
	writeChunk(&chunk, constant, 1);
	writeChunk(&chunk, OP_CONSTANT, 3);
	writeChunk(&chunk, constant2, 3);
	writeChunk(&chunk, OP_RETURN, 3);

	disassembleChunk(&chunk, "hello");
	freeChunk(&chunk);

	return 0;
}
