#include "common.h"
#include "chunk.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN);
	freeChunk(&chunk);

	printf("hello brooklyn");
	return 0;
}
