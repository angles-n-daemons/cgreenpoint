#include <stdio.h>

#include "./controlflow/bench_for.h"

void runBench() {
  printf("starting benchmark\n");
  benchFor();
  printf("benchmark complete\n");
}
