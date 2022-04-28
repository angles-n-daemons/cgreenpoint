#include "common.h"
#include "vm/chunk.h"
#include "debug.h"
#include "test/vm/test_chunk.h"

int main(int argc, const char* argv[]) {
	testChunk();
	printf("all tests pass\n");
	return 0;
}
