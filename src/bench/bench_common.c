#include <stdlib.h>

#include "../main/common.h"
#include "../main/vm/vm.h"

#include <sys/time.h>

long long timems(void) {
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

void benchmark(const char *test, int count) {
  if (count == 0) {
    count = 100000;
  }
  struct timeval stop, start;
  gettimeofday(&start, NULL);
  printf("benchmarking greenpoint program '%s'\n", test);

  for (int i = 0; i < count; i++) {
    initVM();
    interpret(test);
    freeVM();
  }

  gettimeofday(&stop, NULL);
  long durationMicro =
      (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
  printf("program completed %d iterations in %luus\n", count, durationMicro);
  printf("end benchmark\n\n");
}
