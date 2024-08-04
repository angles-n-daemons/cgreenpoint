var start = clock();
var shouldContinue = true;

while (shouldContinue) {
  if (clock() - start > 0.5) {
    shouldContinue = false;
  }
}
